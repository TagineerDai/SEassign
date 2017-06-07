#include "clientWindow.h"

clientWindow::clientWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	timer->setInterval(1000);//Real time = virtual time
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
	//client = ClientAC();
	client = ClientAC(room, Tinit);
	//Moved to when receiving S_I();
	
	//GUI
	this->setGeometry(100, 100, 400, 350);
	initLabel();

	C_I(); //require to enter the system.
	timer->start();
}

clientWindow::~clientWindow() {}

void clientWindow::updateFunction() {

	//TODO : check the autoUpdate value
	if (client.power == true) {
		if (client.run == false) {
			//自动温度变化
			if (client.Tenv - client.Tcurrent > cfg.Vtemp)
				client.Tcurrent += cfg.Vtemp;
			else if (client.Tenv > client.Tcurrent)
				client.Tcurrent = client.Tenv;
			else if (client.Tcurrent - client.Tenv > cfg.Vtemp)
				client.Tcurrent -= cfg.Vtemp;
			else if (client.Tenv < client.Tcurrent)
				client.Tcurrent = client.Tenv;
			C_C();
			//是否和目标温度相差一度？
			if (abs(client.Tcurrent - client.Ttarget) > 1.0 && client.req == false) {
				client.req = true;
				C_T();
			}
		}
		else {//client.run == true
			//温度中央空调控制
			//是否达到目标温度
			if (client.Ttarget >= client.Tcurrent && client.mode == COOL ||
				client.Ttarget <= client.Tcurrent && client.mode == WARM) {//达到目标温度
				client.req = false;
				//			到达目标温度，到达后是否停止工作是谁控制?自己停止还是受到S_A以后?
				//client.run = false;  暂定受到S_A以后 

				C_G();
			}
		}
	}
	else {//client.power == false
		//自动温度变化
		if (client.Tenv - client.Tcurrent > cfg.Vtemp)
			client.Tcurrent += cfg.Vtemp;
		else if (client.Tenv > client.Tcurrent)
			client.Tcurrent = client.Tenv;
		else if (client.Tcurrent - client.Tenv > cfg.Vtemp)
			client.Tcurrent -= cfg.Vtemp;
		else if (client.Tenv < client.Tcurrent)
			client.Tcurrent = client.Tenv;
		C_C();
	}

	//GUI update;
	updateLabel();
}

void clientWindow::initLabel() {
	client.roomID = room;
	this->ui.LroomID->setText((QString::number(client.roomID, 10) + QString("号房间")));
	this->ui.Ltime->setText(QDateTime::currentDateTime().toString(QString("yyyy年MM月dd日 HH:mm:ss")));

	this->ui.Ncost->display(client.cost);
	this->ui.NTnow->display(client.Tcurrent);
	this->ui.NTtarget->display(client.Ttarget);

	this->ui.Lwait->setText("否");
	this->ui.LWcurrent->setText("无");
	this->ui.LWtarget->setText("中");

	this->ui.Bsubmit->setDisabled(true);
	this->ui.W1->setCheckable(false);
	this->ui.W2->setCheckable(false);
	this->ui.W3->setCheckable(false);

	this->ui.Bon->setText(QString("开机"));
	return;
}

void clientWindow::updateLabel() {
	this->ui.LroomID->setText((QString::number(client.roomID, 10) + QString("号房间")));
	this->ui.Ltime->setText(QDateTime::currentDateTime().toString(QString("yyyy年MM月dd日 HH:mm:ss")));

	this->ui.Ncost->display(client.cost);
	this->ui.NTnow->display(client.Tcurrent);

	if(client.power==false){//关机状态下
		this->ui.NTtarget->display("--");

		this->ui.Lwait->setText("否");
		this->ui.LWcurrent->setText(WIND2Qstr(NON));
		this->ui.LWtarget->setText(WIND2Qstr(client.wind));

		this->ui.Bsubmit->setDisabled(true);
		this->ui.STemp->setRange(client.Tfloor, client.Tcell);
		this->ui.STemp->setValue(client.Tdefault);
		this->ui.STemp->setDisabled(true);
		this->ui.W1->setCheckable(false);
		this->ui.W2->setCheckable(false);
		this->ui.W3->setCheckable(false);

		this->ui.Bon->setText(QString("开机"));
		this->ui.Bcout->setDisabled(false);
	}
	else {//开机状态下：
		this->ui.NTtarget->display(client.Ttarget);
		
		if (client.req == true && client.run == false)
			this->ui.Lwait->setText("是");
		else this->ui.Lwait->setText("否");
		
		if(client.run == false) this->ui.LWcurrent->setText("无风");
		else
			switch (client.wind) {
			case HIGH:
				this->ui.LWcurrent->setText("高速");
				break;
			case MEDIUM:
				this->ui.LWcurrent->setText("中速");
				break;
			case LOW:
				this->ui.LWcurrent->setText("低速");
				break;
			}

		switch (client.wind) {
		case HIGH:
			this->ui.LWtarget->setText("高速");
			break;
		case MEDIUM:
			this->ui.LWtarget->setText("中速");
			break;
		case LOW:
			this->ui.LWtarget->setText("低速");
			break;
		}
		
		this->ui.Bsubmit->setDisabled(false);
		this->ui.STemp->setDisabled(false);
		this->ui.W1->setCheckable(true);
		this->ui.W2->setCheckable(true);
		this->ui.W3->setCheckable(true);

		this->ui.Bon->setText("关机");
		this->ui.Bcout->setDisabled(true);
	}
}

//room functional buttons

//Quit button
void clientWindow::on_Bcout_clicked() {
	{
		qDebug() << "closeButton | 退房";
		if (client.power == true) {
			qDebug() << "请先关机，开机状态下无法退房。";
			QMessageBox::warning(NULL, "提示", "请先关机，开机状态下无法退房。", QMessageBox::Yes | QMessageBox::Cancel);
			return;
		}
		qDebug() << "账单" << client.cost;
		QString str = QString("账单共计") + QString::number(client.cost, 'g', 2) + QString("元，是否现在退房并结账？");
		int checkout = QMessageBox::question(NULL, "退房", str, QMessageBox::Yes | QMessageBox::No);
		switch (checkout) {
		case QMessageBox::Yes: {
			qDebug() << "Quit? Y";
			C_Q();
			//主控机直接收close()会雪崩
			//不要直接点close啊啊啊啊！quit！quit就行了！
			break; }
		case QMessageBox::No:
		default: {
			qDebug() << "Quit? N";
			return;
			break; 
		}
		}
	}
}

//Power button
void clientWindow::on_Bon_clicked() {
	int acoff = QString::compare(this->ui.Bon->text(), QString("关机"));
	if (acoff == 0) {//关机
		client.power_off();
		C_E();
	}
	else {//开机
		client.power_on();
		C_B();
	}
	updateLabel();
}

//submit the Ttarget / Wind
void clientWindow::on_Bsubmit_clicked() {

	client.set_temp_target(this->ui.STemp->value());
	C_T();
	qDebug() << "Send T" << client.Ttarget;

	client.set_wind((WIND)windbtn);
	C_R();
	qDebug() << "Send R" << windbtn;
	updateLabel();
}

//Press wind btns
void clientWindow::on_W1_clicked() {
	windbtn = 1;
	qDebug() << "PRESSED WIND LOW";
	updateLabel();
}

void clientWindow::on_W2_clicked() {
	windbtn = 2;
	qDebug() << "PRESSED WIND MEDIUM";
	updateLabel();
}

void clientWindow::on_W3_clicked() {
	windbtn = 3;
	qDebug() << "PRESSED WIND HIGH";
	updateLabel();
}

//Connected()

void clientWindow::connected() {
	qDebug() << "Client Connected with " << hostAddr << '@' << hostPort;
}

//Read message ServerAC --> ClientAC


void clientWindow::clientRead() {
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_5_2);
	while (tcpSocket->bytesAvailable()) {
		in >> blockSize;
		if (blockSize <= 0)
			break;
		in >> type;
		switch (type) {
		case quint8('I'): {
			bool success;
			in >> success;
			qDebug() << "S_I 进入房间 " << success;
			if (!success){//S_I getting into the room --> false
				int retry = QMessageBox::warning(NULL, "提示", "连接被拒绝，是否重试？", 
					QMessageBox::Yes | QMessageBox::Cancel);
				if (retry == QMessageBox::Yes)
					C_I();
				else
					close();
			}
			else { //S_I getting into the room --> true
				qDebug() << "房间初始化 id为:" << room;
				client.room_in_accepted();
			}
			break;
		}

		case quint8('P'): {
			bool iscool, tosendT;
			MODE mode;
			int windtemp;
			double Tfloor, Tcell, Tdefault;
			in >> iscool;
			if (iscool) mode = COOL;
			else mode = WARM;
			in >> Tfloor;
			in >> Tcell;
			in >> Tdefault;
			in >> windtemp;
			qDebug() << "S_P" << mode << Tfloor << Tcell << Tdefault << windtemp;
			switch (windtemp) {
			case 1:
				this->ui.W1->setChecked(true);
				this->ui.W2->setChecked(false);
				this->ui.W3->setChecked(false);

				break;
			case 2:
				this->ui.W2->setChecked(true);
				this->ui.W1->setChecked(false);
				this->ui.W3->setChecked(false);
				break;
			case 3:
				this->ui.W3->setChecked(true);
				this->ui.W1->setChecked(false);
				this->ui.W2->setChecked(false);
				break;
			}
			tosendT = client.work_mode_received(mode, Tfloor, Tcell, Tdefault, WIND(windtemp));
			//wind and Ttarget should be sent out when power on
			//qDebug() << "P reset pattern:" << client.mode << " " << client.Tfloor << " "
			//	<< client.Tcell << " " << client.Tdefault << " " << client.wind;
			if (tosendT) {
				client.set_temp_target(client.Tdefault);
				C_T();
				qDebug() << "Send Tdefault as Ttarget" << client.Ttarget;
			}
			break;
		}

		case quint8('O'): {
			in >> client.cost;
			in >> client.Tcurrent;
			qDebug() << "S_O " << client.cost << client.Tcurrent;
			break;
		}

		//TODO S_H
		case quint8('H'): {
			if (client.power == true) {
				bool ishang;
				in >> ishang;
				if (!ishang && client.req==true) {//被调度
					client.run = true;
				}
				else {//挂起
					client.run = false;
				}
				qDebug() << "H " << ishang;
			}
			else {
				qDebug() << "Received dispatch when there is no request.";
			}
			break;
		}
						  
		//TODO S_A
		case quint8('A'): {
			client.req = false;
			client.run = false;
			qDebug() << "A received";
			break;
		}
		
		//deleted S_C message
		/*
		case quint8('C'): {
			in >> client.Tcurrent;
			qDebug() << "C " << client.Tcurrent;
			break; 
		}
		*/

		}//case
	}
	emit dataRecived();
}

//Send message ClientAC --> ServerAC

void clientWindow::C_I() {
	qDebug() << "C_I"<< tcpSocket->isOpen();
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
	qDebug() << "C_B";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('B') << client.roomID;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_E() {
	block.clear();
	qDebug() << "C_E";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('E') << client.roomID;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_Q() {
	block.clear();
	qDebug() << "C_Q";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('Q') << client.roomID;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
	close();
}

void clientWindow::C_R() {
	block.clear();
	qDebug() << "C_R" << (int)client.wind;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('R') << client.roomID << (int)client.wind;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_C() {
	block.clear();
	qDebug() << "C_C" << client.Tcurrent;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('C') << client.roomID << client.Tcurrent;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_T() {
	block.clear();
	qDebug() << "C_T" << client.Ttarget;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('T') << client.roomID << client.Ttarget;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	tcpSocket->write(block);
}

void clientWindow::C_G() {
	block.clear();
	qDebug() << "C_G";
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('G') << client.roomID;
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