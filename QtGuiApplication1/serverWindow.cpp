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
	qDebug() << "New connect!!!!!";
	QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
	connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
	connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
	tcpConnects.append(clientSocket);
	//ONLY readClient() TODO
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
	in.setVersion(QDataStream::Qt_5_5);
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
		qDebug() << "The type code: " << type;
		switch (type) {
		case quint8('I'): {
			in >> cid;
			double Tinit;
			in >> Tinit;
			if (server->filled[cid] == true) {
				S_I(client, cid, false);
				qDebug() << cid << "Accepted and send S_I message";
			}
			else {
				S_I(client, cid, true);
				qDebug() << cid << "Rejected and send S_I message";
				target[cid] = client;
				server->filled[cid] = true;
			}
			break;
		}
		case quint8('B'): {
			in >> cid;
			clients[cid]->work = ON;
			qDebug() << "Recv B " << cid; ;
			break;
		}
		case quint8('E'): {
			in >> cid;
			clients[cid]->work = OFF;
			qDebug() << "Recv E " << cid; ;
			break;
		}
		case quint8('Q'): {
			in >> cid;
			server->filled[cid] = false;
			target[cid] = nullptr;
			clients[cid] = new ClientAC(cid, -1);
			client->abort();
			qDebug() << "Recv Q " << cid; ;
			break;
		}
		case quint8('T'):
		case quint8('G'): {
			in >> cid;
			double Ttarget;
			in >> Ttarget;
			clients[cid]->Ttarget = Ttarget;
			reqs[cid].handle = false; //waiting for dispatch
			qDebug() << "Recv Q " << cid << ' ' << Ttarget;

			break;
		}
		case quint8('R'): {
			in >> cid;
			int wind;
			in >> wind;
			clients[cid]->wind = (WIND)wind;
			reqs[cid].handle = false; //waiting for dispatch
			qDebug() << "Recv R " << cid << ' ' << wind;

			break;
		}
		}
		blockSize = 0;//Loop!!!
	}
	emit dataRecivedS();
}
void serverWindow::S_I(QTcpSocket* sock, int id,  bool success) {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_7);
	out << quint16(0) <<quint8('I') << success;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	sock->write(block);
	if (success) {
		target[id] = sock;
	}
}
void serverWindow::S_P(QTcpSocket* sock) {

}
void serverWindow::S_O(QTcpSocket* sock, double cost, double Tcurrent) {

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
	qDebug() << server->work;
	timer->start();
	this->ui.Ldate->setVisible(true);
	this->ui.Ltime_2->setVisible(true);
	server->work = ON;
	this->ui.Bpower->setText("关机");
	qDebug() << listenAddr << ' '<<  listenPort;
	qDebug() << "Build the Tcp connect | 开机";
}
void serverWindow::power_off() {
	tcpServer->close();
	timer->stop();
	this->ui.Ldate->setVisible(false);
	this->ui.Ltime_2->setVisible(false);
	qDebug() << server->work;
	this->ui.Bpower->setText("开机");
	server->work = OFF;
	qDebug() << "Stop the Tcp connect";
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
