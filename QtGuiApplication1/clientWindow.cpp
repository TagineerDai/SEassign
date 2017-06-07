#include "clientWindow.h"

clientWindow::clientWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	timer->setInterval(1000);//Real time = virtual time
	timer->setSingleShot(false);

	// ˢ���������£��յ���Ϣ | ÿ�����
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
			//�Զ��¶ȱ仯
			if (client.Tenv - client.Tcurrent > cfg.Vtemp)
				client.Tcurrent += cfg.Vtemp;
			else if (client.Tenv > client.Tcurrent)
				client.Tcurrent = client.Tenv;
			else if (client.Tcurrent - client.Tenv > cfg.Vtemp)
				client.Tcurrent -= cfg.Vtemp;
			else if (client.Tenv < client.Tcurrent)
				client.Tcurrent = client.Tenv;
			C_C();
			//�Ƿ��Ŀ���¶����һ�ȣ�
			if (abs(client.Tcurrent - client.Ttarget) > 1.0 && client.req == false) {
				client.req = true;
				C_T();
			}
		}
		else {//client.run == true
			//�¶�����յ�����
			//�Ƿ�ﵽĿ���¶�
			if (client.Ttarget >= client.Tcurrent && client.mode == COOL ||
				client.Ttarget <= client.Tcurrent && client.mode == WARM) {//�ﵽĿ���¶�
				client.req = false;
				//			����Ŀ���¶ȣ�������Ƿ�ֹͣ������˭����?�Լ�ֹͣ�����ܵ�S_A�Ժ�?
				//client.run = false;  �ݶ��ܵ�S_A�Ժ� 

				C_G();
			}
		}
	}
	else {//client.power == false
		//�Զ��¶ȱ仯
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
	this->ui.LroomID->setText((QString::number(client.roomID, 10) + QString("�ŷ���")));
	this->ui.Ltime->setText(QDateTime::currentDateTime().toString(QString("yyyy��MM��dd�� HH:mm:ss")));

	this->ui.Ncost->display(client.cost);
	this->ui.NTnow->display(client.Tcurrent);
	this->ui.NTtarget->display(client.Ttarget);

	this->ui.Lwait->setText("��");
	this->ui.LWcurrent->setText("��");
	this->ui.LWtarget->setText("��");

	this->ui.Bsubmit->setDisabled(true);
	this->ui.W1->setCheckable(false);
	this->ui.W2->setCheckable(false);
	this->ui.W3->setCheckable(false);

	this->ui.Bon->setText(QString("����"));
	return;
}

void clientWindow::updateLabel() {
	this->ui.LroomID->setText((QString::number(client.roomID, 10) + QString("�ŷ���")));
	this->ui.Ltime->setText(QDateTime::currentDateTime().toString(QString("yyyy��MM��dd�� HH:mm:ss")));

	this->ui.Ncost->display(client.cost);
	this->ui.NTnow->display(client.Tcurrent);

	if(client.power==false){//�ػ�״̬��
		this->ui.NTtarget->display("--");

		this->ui.Lwait->setText("��");
		this->ui.LWcurrent->setText(WIND2Qstr(NON));
		this->ui.LWtarget->setText(WIND2Qstr(client.wind));

		this->ui.Bsubmit->setDisabled(true);
		this->ui.STemp->setRange(client.Tfloor, client.Tcell);
		this->ui.STemp->setValue(client.Tdefault);
		this->ui.STemp->setDisabled(true);
		this->ui.W1->setCheckable(false);
		this->ui.W2->setCheckable(false);
		this->ui.W3->setCheckable(false);

		this->ui.Bon->setText(QString("����"));
		this->ui.Bcout->setDisabled(false);
	}
	else {//����״̬�£�
		this->ui.NTtarget->display(client.Ttarget);
		
		if (client.req == true && client.run == false)
			this->ui.Lwait->setText("��");
		else this->ui.Lwait->setText("��");
		
		if(client.run == false) this->ui.LWcurrent->setText("�޷�");
		else
			switch (client.wind) {
			case HIGH:
				this->ui.LWcurrent->setText("����");
				break;
			case MEDIUM:
				this->ui.LWcurrent->setText("����");
				break;
			case LOW:
				this->ui.LWcurrent->setText("����");
				break;
			}

		switch (client.wind) {
		case HIGH:
			this->ui.LWtarget->setText("����");
			break;
		case MEDIUM:
			this->ui.LWtarget->setText("����");
			break;
		case LOW:
			this->ui.LWtarget->setText("����");
			break;
		}
		
		this->ui.Bsubmit->setDisabled(false);
		this->ui.STemp->setDisabled(false);
		this->ui.W1->setCheckable(true);
		this->ui.W2->setCheckable(true);
		this->ui.W3->setCheckable(true);

		this->ui.Bon->setText("�ػ�");
		this->ui.Bcout->setDisabled(true);
	}
}

//room functional buttons

//Quit button
void clientWindow::on_Bcout_clicked() {
	{
		qDebug() << "closeButton | �˷�";
		if (client.power == true) {
			qDebug() << "���ȹػ�������״̬���޷��˷���";
			QMessageBox::warning(NULL, "��ʾ", "���ȹػ�������״̬���޷��˷���", QMessageBox::Yes | QMessageBox::Cancel);
			return;
		}
		qDebug() << "�˵�" << client.cost;
		QString str = QString("�˵�����") + QString::number(client.cost, 'g', 2) + QString("Ԫ���Ƿ������˷������ˣ�");
		int checkout = QMessageBox::question(NULL, "�˷�", str, QMessageBox::Yes | QMessageBox::No);
		switch (checkout) {
		case QMessageBox::Yes: {
			qDebug() << "Quit? Y";
			C_Q();
			//���ػ�ֱ����close()��ѩ��
			//��Ҫֱ�ӵ�close����������quit��quit�����ˣ�
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
	int acoff = QString::compare(this->ui.Bon->text(), QString("�ػ�"));
	if (acoff == 0) {//�ػ�
		client.power_off();
		C_E();
	}
	else {//����
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
			qDebug() << "S_I ���뷿�� " << success;
			if (!success){//S_I getting into the room --> false
				int retry = QMessageBox::warning(NULL, "��ʾ", "���ӱ��ܾ����Ƿ����ԣ�", 
					QMessageBox::Yes | QMessageBox::Cancel);
				if (retry == QMessageBox::Yes)
					C_I();
				else
					close();
			}
			else { //S_I getting into the room --> true
				qDebug() << "�����ʼ�� idΪ:" << room;
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
				if (!ishang && client.req==true) {//������
					client.run = true;
				}
				else {//����
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
		QMessageBox::warning(NULL, "����", "Ŀ���ַδ�ҵ������򼴽��رա�����Ŀ���ַ�Ͷ˿ںš�", QMessageBox::Yes | QMessageBox::Cancel);

		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::warning(NULL, "����", "������δ���У�����Ŀ���ַ�Ͷ˿ںŴ��󣬳��򼴽��رա�", QMessageBox::Yes | QMessageBox::Cancel);

		//QMessageBox::information(this, tr("Blocking Fortune Client"),
		//	tr("The connection was refused by the peer. "
		//		"Make sure the fortune server is running, "
		//		"and check that the host name and port "
		//		"settings are correct."));
		break;
	default:
		//ֻ�������˷�ʱ��δ֪����
		//QMessageBox::information(this, tr("Blocking Fortune Client"),
		//	tr("The following error occurred: Unknown error."));
		QString str = QString("�˵�����") + QString::number(client.cost, 'g', 2) + QString("Ԫ���Ѿ���ǰ̨�˷�������");
		QMessageBox::warning(NULL, "�˷�", str, QMessageBox::Yes | QMessageBox::Cancel);
		close();
		break;
	}
	close();
	//TODO:
	// stop the close()
	// client.state = OFFC;
	// updateLabel();
}