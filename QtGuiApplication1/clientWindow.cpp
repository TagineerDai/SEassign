#include "clientWindow.h"

clientWindow::clientWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);

	timer->setInterval(1000 * cfg.interval);
	timer->setSingleShot(false);
	// 刷新条件更新：收到信息 | 每秒更新
	connect(timer, SIGNAL(timeout()), this, SLOT(updateFunction()));
	connect(this, SIGNAL(dataRecived()), this, SLOT(updateFunction()));
	tcpSocket = new QTcpSocket(this);
	qDebug() << "Try to Connect with "<< hostAddr << ' ' << hostPort;
	tcpSocket->connectToHost(hostAddr, hostPort);
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(clientRead()));
	
	//two error message? //TODO
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(displayError(QAbstractSocket::SocketError)));
	//INIT
	client.roomID = room;
	client.Tenv = Tinit;
	client.Tcurrent = Tinit;
	client.state = OFFC;
	//client.autoUpdate = true;
	//client.waiting = false;
	//moved into ClientAC.h member init
	
	//GUI
	this->setGeometry(100, 100, 400, 350);
	/*
	this->ui.LroomID->setText((QString::number(client.roomID, 10) + QString("号房间")));
	this->ui.NTnow->display(client.Tcurrent);
	this->ui.NTtarget->display("--");
	this->ui.Ncost->display(0);
	this->ui.Lconnect->setText("等待");
	this->ui.Bon->setText(QString("开机"));
	this->ui.Ltime->setText(QString(""));
	this->ui.Bon->setCheckable(false);
	this->ui.W1->setCheckable(false);
	this->ui.W2->setCheckable(false);
	this->ui.W3->setCheckable(false);
	this->ui.Btemp->setDisabled(true);
	this->ui.Bon->setDisabled(true);
	this->ui.STemp->setDisabled(true);
	this->ui.Lwind->setText("无风");
	this->ui.Lwait->setText("是");
	*/
	updateLabel();
	C_I();
	timer->start();
}

clientWindow::~clientWindow()
{
}

void clientWindow::updateFunction() {

	//TODO : check the autoUpdate value
	
	if (!client.autoUpdate && client.work == ON) {//开机 | 并由主机控制
		if (client.Ttarget == client.Tcurrent) {
			//达到目标温度(receive A)
			client.waiting = false;
			client.autoUpdate = true;
		}
	}
	else{//自动变化
		if (client.Tcurrent > client.Tenv)
			client.Tcurrent -= 0.03;
		if (client.Tcurrent < client.Tenv)
			client.Tcurrent += 0.03;
		if (client.work == ON && client.waiting == false && abs(client.Tcurrent - client.Ttarget) > 1) {
			C_G();
			//client.waiting == false ： make sure C_G() be sent only once;
			client.waiting = true;
		}
	}
	//GUI update;
	updateLabel();
	C_C();
}

void clientWindow::updateLabel() {
	this->ui.Ltime->setText(QDateTime::currentDateTime().toString(QString("yyyy年MM月dd日 HH:mm:ss")));
	this->ui.STemp->setRange(client.Tfloor, client.Tcell);
	switch (client.state) {
	case ONC:
		this->ui.Bon->setDisabled(false);
		this->ui.Bon->setCheckable(true);
		this->ui.Ncost->display(client.cost);
		this->ui.NTnow->display(client.Tcurrent);
		if (client.work) { //ON
			this->ui.Bon->setText("关机");
			this->ui.NTtarget->display(client.Ttarget);
			switch (client.wind) {
			case HIGH:
				this->ui.Lwind->setText("高速");
				break;
			case MEDIUM:
				this->ui.Lwind->setText("中速");
				break;
			case LOW:
				this->ui.Lwind->setText("低速");
				break;
			}
			if (this->ui.W1->isCheckable() == false) {
				this->ui.W1->setCheckable(true);
				this->ui.W2->setCheckable(true);
				this->ui.W3->setCheckable(true);
				switch (client.wind) {
				case(HIGH):
					this->ui.W3->setChecked(true);
					break;
				case(MEDIUM):
					this->ui.W2->setChecked(true);
					break;
				case(LOW):
					this->ui.W1->setChecked(true);
					break;
				}
			}
			this->ui.Btemp->setDisabled(false);
			this->ui.STemp->setDisabled(false);
			this->ui.Bcout->setDisabled(true);
		}
		else { //OFF
			this->ui.Bon->setText("开机");
			this->ui.NTtarget->display("--");
			this->ui.Lwind->setText("无风");
			this->ui.W1->setCheckable(false);
			this->ui.W2->setCheckable(false);
			this->ui.W3->setCheckable(false);
			this->ui.Btemp->setDisabled(true);
			this->ui.STemp->setDisabled(true);
			this->ui.Bcout->setDisabled(false);
		}
		this->ui.Lconnect->setText("正常");
		if (client.waiting && client.work == ON)
			this->ui.Lwait->setText("是");
		else
			this->ui.Lwait->setText("否");
		break;
	case OFFC:
	default:
		this->ui.Bcout->setCheckable(true);
		this->ui.Bon->setCheckable(false);
		this->ui.W1->setCheckable(false);
		this->ui.W2->setCheckable(false);
		this->ui.W3->setCheckable(false);
		this->ui.Btemp->setDisabled(true);
		this->ui.Bon->setDisabled(true);
		this->ui.STemp->setDisabled(true);
		this->ui.Lconnect->setText("等待");
		this->ui.Ncost->display("--");
		this->ui.NTnow->display(client.Tcurrent);
		this->ui.NTtarget->display("--");
		this->ui.Lwait->setText("是");
		this->ui.Lwind->setText("无风");
		break;
	}
}

//room functional buttons

void clientWindow::on_Bcout_clicked() {
	{
		qDebug() << "closeButton | 退房";
		if (client.work == ON) {
			qDebug() << "请先关机，开机状态下无法退房。";
			QMessageBox::warning(NULL, "提示", "请先关机，开机状态下无法退房。", QMessageBox::Yes | QMessageBox::Cancel);
			return;
		}
		//int costnow = (int)client.cost;
		//qDebug() << "账单" << client.cost;
		QString str = QString("账单共计") + QString::number(client.cost, 'g', 2) + QString("元，是否现在退房并结账？");
		int checkout = QMessageBox::question(NULL, "退房", str, QMessageBox::Yes | QMessageBox::No);
		switch (checkout) {
		case QMessageBox::Yes:
			qDebug() << "Y";
			C_Q();
			//主控机直接收close()会雪崩
			//close window 统一在C_Q之后吧
			break;
		case QMessageBox::No:
		default:
			qDebug() << "N";
			return;
			break;
		}
	}
}

void clientWindow::on_Bon_clicked() {
	int acoff = QString::compare(this->ui.Bon->text(), QString("关机"));
	if (acoff == 0) {//关机
		//this->ui.Bcout->setDisabled(false);
		//timer->stop();
		client.work = OFF;
		client.autoUpdate = true;
		C_E();
		updateLabel();
		//发送信息和更新的顺序必须不能变。。。
	}
	else {//开机
		//timer->start();
		qDebug() << "SEND AC POWER ON//TODO";
		qDebug() << "SEND the FIRST req";
		client.work = ON;
		C_B();// immediately stoped by the Mode received from the server;
		//to stop the next req to be recived.
		//C_T();
		//C_R();
		updateLabel();
	}
}

void clientWindow::on_Btemp_clicked() {
	client.Ttarget = this->ui.STemp->value();
	C_T();
}

void clientWindow::on_W1_clicked() {
	if (client.wind == LOW || client.work == OFF)
		return;
	client.waiting = true;
	client.wind = LOW;
	C_R();
	qDebug() << "REQ WIND LOW";
}

void clientWindow::on_W2_clicked() {
	if (client.wind == MEDIUM || client.work == OFF)
		return;
	client.wind = MEDIUM;
	client.waiting = true;
	C_R();
	qDebug() << "REQ WIND MEDIUM";
}

void clientWindow::on_W3_clicked() {
	if (client.wind == HIGH || client.work == OFF)
		return;
	client.wind = HIGH;
	client.waiting = true;
	C_R();
	qDebug() << "REQ WIND HIGH";
}

//Connected()

void clientWindow::connected() {
	qDebug() << "Client Connected with " << hostAddr << '@' << hostPort;
}

//Read message ServerAC --> ClientAC

void clientWindow::clientRead() {
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_5_2);
	while (tcpSocket->bytesAvailable() > 0) {
		in >> blockSize;
		in >> type;
		switch (type) {
		case quint8('I'): {
			bool success;
			in >> success;
			if (success) {
				client.state = ONC;
			}
			else {
				int retry = QMessageBox::warning(NULL, "提示", "连接被拒绝，是否重试？", 
					QMessageBox::Yes | QMessageBox::Cancel);
				if (retry == QMessageBox::Yes)
					C_I();
				else
					close();
			}
			//For the waiting login of role=ROOM
			qDebug() << "进入房间 " << success;
			break;
		}
		case quint8('P'): {
			bool iscool;
			in >> iscool;
			if (iscool) client.mode = COOL;
			else client.mode = WARM;
			in >> client.Tfloor;
			in >> client.Tcell;
			in >> client.Tdefault;
			int winds;
			in >> winds;
			client.Dwind= WIND(winds);
			client.Ttarget = client.Tdefault;
			C_T();
			client.wind = client.Dwind;
			C_R();
			qDebug() << "P " << client.mode << " " << client.Tfloor << " "
				<< client.Tcell << " " << client.Tdefault << " " << client.Dwind;
			break;
		}
		case quint8('C'): {//unused 
			in >> client.Tcurrent;
			qDebug() << "C " << client.Tcurrent;
			break; 
		}
		case quint8('O'): {
			in >> client.cost;
			in >> client.Tcurrent;
			qDebug() << "O " << client.cost << client.Tcurrent;
			break;
		}
		case quint8('A'): {
			client.autoUpdate = true;
			qDebug() << "A";
			break;
		}
		case quint8('H'): {
			bool ishang;
			in >> ishang;
			if (!ishang) {//调度
				client.waiting = false;
				client.autoUpdate = false;
			}
			else {//挂起
				client.waiting = true;
				client.autoUpdate = true;
			}
			qDebug() << "H " << ishang;
			break;
		}
		}
	}
	emit dataRecived();
}

//Send message ClientAC --> ServerAC

void clientWindow::C_I() {
	qDebug() << "I "<< tcpSocket->isOpen();
	block.clear();
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('I') << client.roomID << client.Tenv;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_B() {
	block.clear();
	qDebug() << "Send B";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('B') << client.roomID;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_E() {
	block.clear();
	qDebug() << "Send E";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('E') << client.roomID;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_Q() {
	block.clear();
	qDebug() << "Send Chick out -- Q";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('Q') << client.roomID;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
	close();
}

void clientWindow::C_T() {
	block.clear();
	qDebug() << "Send Target temp" << client.Ttarget;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('T') << client.roomID << client.Ttarget;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_G() {
	block.clear();
	qDebug() << "Send G";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('G') << client.roomID << client.Ttarget;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_C() {
	block.clear();
	qDebug() << "Send C" << client.Tcurrent;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('C') << client.roomID << client.Tcurrent;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_R() {
	block.clear();
	qDebug() << "Send Wind";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_7);
	out << quint16(0) << quint8('R') << client.roomID << (int)client.wind;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

//Socket Error display | exit when quit
void clientWindow::displayError(QAbstractSocket::SocketError socketError) {
	switch (socketError) {
	case QAbstractSocket::HostNotFoundError:
		//QMessageBox::information(this, tr("Blocking Fortune Client"),
		//	tr("The host was not found. Please check the "
		//		"host and port settings."));
		QMessageBox::warning(NULL, "错误", "目标地址未找到，程序即将关闭。请检查目标地址和端口号。", QMessageBox::Yes | QMessageBox::Cancel);

		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::warning(NULL, "错误", "服务器未运行，或者目标地址和端口号错误，程序即将关闭。", QMessageBox::Yes | QMessageBox::Cancel);

		//QMessageBox::information(this, tr("Blocking Fortune Client"),
		//	tr("The connection was refused by the peer. "
		//		"Make sure the fortune server is running, "
		//		"and check that the host name and port "
		//		"settings are correct."));
		break;
	default:
		//只在主机退房时报未知错误
		//QMessageBox::information(this, tr("Blocking Fortune Client"),
		//	tr("The following error occurred: Unknown error."));
		QString str = QString("账单共计") + QString::number(client.cost, 'g', 2) + QString("元，已经在前台退房并结账");
		QMessageBox::warning(NULL, "退房", str, QMessageBox::Yes | QMessageBox::Cancel);
		close();
		break;
	}
	close();
	//TODO:
	// stop the close()
	// client.state = OFFC;
	// updateLabel();
}