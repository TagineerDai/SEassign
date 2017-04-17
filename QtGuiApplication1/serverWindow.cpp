#include "serverWindow.h"

serverWindow::serverWindow(QWidget *parent)
	: QWidget(parent)
{
	//ui init
	ui.setupUi(this);

	//entity init
	server = new ServerAC(cfg);
	server->filled[1] = false;
	server->filled[2] = false;
	server->filled[3] = false;
	server->filled[4] = false;
	server->work = OFF;
	
	for (int i = 1; i < 5; i++) {
		clients[i] = new ClientAC(i, -1);//Tenv=-1
		reqs[i].handle = true;
		reqs[i].roomID = i;
	}

	//flush init
	timer = new QTimer(this);
	timer->setInterval(1000 * cfg.interval);
	timer->setSingleShot(false);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateFunction()));

	//GUI init
	this->setGeometry(100, 100, 500, 600);
	this->ui.Lstate->setText(server->toString());
	this->ui.Ldate->setText(QString(""));
	this->ui.Ltime_2->setText(QString(""));
	if (server->work == OFF) {
		this->ui.Bpower->setText(QString("开机"));
		this->ui.Ldate->setVisible(false);
		this->ui.Ltime_2->setVisible(false);
	}
	else this->ui.Bpower->setText(QString("关机"));

	this->ui.CTcell->setValue(server->Tcell);
	this->ui.CTfloor->setValue(server->Tfloor);
	this->ui.CTdefault->setValue(server->Tdefault);

	switch (server->mode) {
	case COOL:
		this->ui.Bcool->setChecked(true);
		break;
	case WARM:
		this->ui.Bwarm->setChecked(true);
	}
}

serverWindow::~serverWindow()
{
	tcpServer->close();
	delete tcpServer;
}

void serverWindow::newConn()
{
	qDebug() << "New tcpConnect() signal from tcpServer";
	QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
	connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
	connect(this, SIGNAL(dataRecivedS()), this, SLOT(updateFunction()));
	connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void serverWindow::on_Bhalt_clicked() 
{
	int sysoff = QString::compare(this->ui.Bpower->text(), QString("关机"));
	if (sysoff)
		switch (QMessageBox::information(this, tr("提示"), tr("确认退出?"), tr("确定"), tr("取消"), 0, 1))
		{
		case 0:
			qDebug() << "WRITE DATABASE" << endl;
			close();
			break;
		case 1:
		default:
			return;
			break;
		}
	else {//DONE
		QMessageBox::warning(NULL, "提示", "请先关机，再进行系统退出。", QMessageBox::Yes | QMessageBox::Cancel);
		return;
	}
}

//TODO LIST of CLIENT / REQ

void serverWindow::readClient() // TODO dublicate
{
	QTcpSocket* client = (QTcpSocket*)sender();
	QDataStream in(client);
	in.setVersion(QDataStream::Qt_5_2);
	blockSize = 0;
	for (;;) {
		if (!blockSize) {//无信息
			if (client->bytesAvailable() < sizeof(quint16)) {
				break;
			}
			in >> blockSize;
		}
		if (client->bytesAvailable() < blockSize) {//合法块大小
			break;
		}

		int cid = 0;
		quint8 type = 0;
		in >> type;
		in >> cid;
		if (cid > 4 || cid < 1) {
			break;//合法的房间号
		}
		qDebug() << "Receive from" << cid << "message" << char(type) << "length" << blockSize;
		switch (type) {
		case quint8('I'): {
			double Tinit;
			in >> Tinit;
			if (server->filled[cid] == true) {
				S_I(client, false);//DONE
				qDebug() << cid << "Rejected and send S_I false message";
			}
			else {
				S_I(client, true); //DONE
				qDebug() << cid << "Accepted and send S_I true message";
				target[cid] = client;
				server->filled[cid] = true;
			}
			break;
		}
		case quint8('B'): {
			clients[cid]->work = ON;
			break;
		}

		case quint8('E'): {
			clients[cid]->work = OFF;
			break;
		}
		case quint8('Q'): {
			server->filled[cid] = false;
			target[cid] = nullptr;
			clients[cid] = new ClientAC(cid, -1);
			client->abort();
			break;
		}
		case quint8('T'):
		case quint8('G'): {
			double Ttarget;
			in >> Ttarget;
			clients[cid]->Ttarget = Ttarget;
			//reqs[cid].handle = false;
			// waiting for dispatch->be dispatched in updateFunction()
			break;
		}
		case quint8('R'): {
			int wind;
			in >> wind;
			clients[cid]->wind = (WIND)wind;
			reqs[cid].handle = false; //waiting for dispatch
			qDebug() << "Recv R " << cid << ' ' << wind;

			break;
		}
		}
		blockSize = 0;
	}
	emit dataRecivedS();
}

/*
void serverWindow::readClient() // TODO dublicate
{
	QTcpSocket* client = (QTcpSocket*)sender();
	int cid;
	QDataStream in(client);
	in.setVersion(QDataStream::Qt_5_2);
	while (client->bytesAvailable() > 0) {
		in >> blockSize;
		in >> type;
		in >> cid;
		if (cid > 4 || cid < 1 || blockSize <= 0) {
			qDebug() << "Error Receive " << blockSize << (char)type << cid;
			return;
		}
		qDebug() << "Receive from " << cid << ":" << (char)type << "length:" << blockSize;
		switch (type) {
		case quint8('I'): {
			double Tinit;
			in >> Tinit;
			if (server->filled[cid] == true) {
				S_I(client, cid, false);//DONE
				qDebug() << cid << "Rejected and send S_I false message";
			}
			else {
				S_I(client, cid, true); //DONE
				qDebug() << cid << "Accepted and send S_I true message";
				target[cid] = client;
				server->filled[cid] = true;
			}
			break;
		}
		case quint8('B'): {
			clients[cid]->work = ON;
			break;
		}

		case quint8('E'): {
			clients[cid]->work = OFF;
			break;
		}
		case quint8('Q'): {
			server->filled[cid] = false;
			target[cid] = nullptr;
			clients[cid] = new ClientAC(cid, -1);
			client->abort();
			break;
		}
		case quint8('T'):
		case quint8('G'): {
			double Ttarget;
			in >> Ttarget;
			clients[cid]->Ttarget = Ttarget;
			reqs[cid].handle = false;// waiting for dispatch->be dispatched in updateFunction()
			break;
		}
		case quint8('R'): {
			int wind;
			in >> wind;
			clients[cid]->wind = (WIND)wind;
			reqs[cid].handle = false; //waiting for dispatch
			qDebug() << "Recv R " << cid << ' ' << wind;

			break;
		}
		}
	}
		//A false version of receive
		/*
	blockSize = 0;
	int cid;
	for (;;) {
		qDebug() << "LOOP~read";
		if (!blockSize) {
			if (client->bytesAvailable() < sizeof(quint16)) {
				break;
			}
			in >> blockSize;
		}//loop init
		if (client->bytesAvailable() < blockSize) {
			break;//wrong block size
		}
		in >> type;
		//Switch type
		qDebug() << "The type code: " << (char)type;
		
		}
		blockSize = 0;//Loop!!!
	}
	emit dataRecivedS();
}
*/
void serverWindow::S_I(QTcpSocket* sock, bool success) {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) <<quint8('I') << success;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	sock->write(block);
}
void serverWindow::S_P(QTcpSocket* sock) {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	bool iscool;
	switch (server->mode) {
	case COOL:
		iscool = true;
		break;
	case WARM:
		iscool = false;
		break;
	}
	int winds = (int)server->Wdefault;
	out << quint16(0) << quint8('P') << iscool << server->Tfloor << server->Tcell << server->Tdefault << winds;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	sock->write(block);
}
void serverWindow::S_O(QTcpSocket* sock, double cost, double Tcurrent) {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('O') << cost << Tcurrent ;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	sock->write(block);
}
void serverWindow::S_H(QTcpSocket* sock, bool hang) {

}
void serverWindow::S_A(QTcpSocket* sock) {

}
//TODO update!!!! Logic and GUI
void serverWindow::updateFunction() {
	updateLabel();
}

void serverWindow::updateLabel() {
	this->ui.Ldate->setText(QDateTime::currentDateTime().toString(QString("yyyy年MM月dd日")));
	this->ui.Ltime_2->setText(QTime::currentTime().toString("时间： HH:mm:ss"));
}

void serverWindow::on_Bpower_clicked() {
	int sysoff = QString::compare(this->ui.Bpower->text(), QString("关机"));
	if (sysoff == 0) {
		power_off();
	}
	else {
		power_on();
	}
}

void serverWindow::power_on() {
	tcpServer = new QTcpServer();
	if (!tcpServer->listen(listenAddr, listenPort)) {
		QMessageBox::warning(NULL, "提示", "TCPServer监听端口失败，请重试。", QMessageBox::Yes | QMessageBox::Cancel);
		return;
	}
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConn()));
	timer->start();
	this->ui.Ldate->setVisible(true);
	this->ui.Ltime_2->setVisible(true);
	server->work = ON;
	this->ui.Bpower->setText("关机");
	qDebug() << listenAddr << ' '<<  listenPort;
	qDebug() << "Build the Tcp connect | 开机" << server->work;
	updateFunction();
}

void serverWindow::power_off() {
	tcpServer->close();
	server->filled[1] = false;
	server->filled[2] = false;
	server->filled[3] = false;
	server->filled[4] = false;
	target[1] = target[2] = target[3] = target[4] = nullptr;
	timer->stop();
	this->ui.Ldate->setVisible(false);
	this->ui.Ltime_2->setVisible(false);
	qDebug() << server->work;
	this->ui.Bpower->setText("开机");
	server->work = OFF;
	qDebug() << "Stop the Tcp connect";
	updateFunction();
}

void serverWindow::on_Bcancel_clicked() {
	if (server->work == OFF) {
		qDebug() << "Messagebox TODO::Warning -- 开机后进行设置调节";
		return;
	}
	qDebug() << "ADMIN | MainWindow -- Pcontrol.on_Bcancel_clicked()";
	this->ui.CTcell->setValue(server->Tcell);
	this->ui.CTfloor->setValue(server->Tfloor);
	this->ui.CTdefault->setValue(server->Tdefault);
	switch (server->mode) {
	case COOL:
		this->ui.Bcool->setChecked(true);
		this->ui.Bwarm->setChecked(false);
		break;
	case WARM:
		this->ui.Bcool->setChecked(false);
		this->ui.Bwarm->setChecked(true);
	}
}

void serverWindow::on_Bcommit_clicked() {
	if (server->work == OFF) {
		qDebug() << "开机后进行设置调节";
		return;
	}
	qDebug() << "ADMIN | MainWindow -- Pcontrol.on_Bcommit_clicked()";
	if (this->ui.Bcool->isChecked()) {
		server->mode = COOL;
		qDebug() << MODE2Qstr(COOL);
	}
	else {
		server->mode = WARM;
		qDebug() << MODE2Qstr(WARM);
	}
	server->Tcell = this->ui.CTcell->value();
	server->Tfloor = this->ui.CTfloor->value();
	server->Tdefault = this->ui.CTdefault->value();
	qDebug() << this->ui.CTcell->value() << " " << this->ui.CTfloor->value() << " " << this->ui.CTdefault->value();
	qDebug() << "SEND -- MODECHANGE";
	this->ui.Lstate->setText(server->toString());
}
//TODO -- Query not now(DB related)
void serverWindow::on_Bquery_clicked() {
	qDebug() << cfg.mode;
	qDebug() << server->mode;
	int rid = this->ui.spinRoom->value();
	qDebug() << "ADMIN | MainWindow -- PDetail.on_Bquery_clicked() -- query room " << rid;
}
