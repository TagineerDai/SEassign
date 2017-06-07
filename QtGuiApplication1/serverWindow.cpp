# pragma execution_character_set("utf-8")
#include "serverWindow.h"
#include <fstream>
serverWindow::serverWindow(QWidget *parent)
	: QWidget(parent)
{
	//ui init
	ui.setupUi(this);
	this->setGeometry(100, 100, 500, 600);

	//entity init
	server = new ServerAC(cfg);
	for (int i = 0; i < 4; i++) {
		clients[i] = new ClientAC(i + 1, -1);//Tenv=-1
		server->filled[i] = false;
		target[i] = nullptr;
	}

	//timer init
	timer = new QTimer(this);
	timer->setInterval(1000); //real time = virtual time
	timer->setSingleShot(false);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateFunction()));

	//GUI init
	initLabel();
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
	connect(this, SIGNAL(dataRecivedS()), this, SLOT(updateLabel()));
	connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}


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
		if (cid > 4 || cid < 1) break;
		qDebug() << "Receive from" << cid << "message" << char(type) << "length" << blockSize;
		switch (type) {

		case quint8('I'): {
			double Tinit;
			in >> Tinit;
			C_I(cid, Tinit, client);
			break;
		}

		case quint8('B'): {
			C_B(cid);
			break;
		}

		case quint8('E'): {
			C_E(cid);
			break;
		}
		
		case quint8('Q'): {
			C_Q(cid);
			break;
		}

		case quint8('R'): {
			int wind;
			in >> wind;
			C_R(cid, wind);
			break;
		}

		case quint8('C'): {
			double Tcurrent;
			in >> Tcurrent;
			C_C(cid, Tcurrent);
			break;
		}
		
		case quint8('T'): {
			double Ttarget;
			in >> Ttarget;
			C_T(cid, Ttarget);
			break;
		}

		case quint8('G'): {
			C_G(cid);
			break;
		}
		}
		blockSize = 0;
	}
	emit dataRecivedS();
}

//cope with received message (cid + info)
void serverWindow::C_I(int roomID, double Tenv, QTcpSocket* client) {
	if (server->filled[roomID - 1] == true && target[roomID - 1] != client) {
		S_I(client, false);//DONE
		qDebug() << roomID << "Rejected and send S_I false message";
	}
	else if (server->filled[roomID - 1] == false) {
		clients[roomID - 1] = new ClientAC(roomID, Tenv);
		target[roomID - 1] = client;
		server->filled[roomID - 1] = true;
		clients[roomID - 1]->room_in_accepted();
		S_I(client, true); //DONE
		qDebug() << roomID << "Accepted and send S_I true message";
	}
	return;
}

void serverWindow::C_B(int roomID) {
	clients[roomID - 1]->power_on();
	qDebug() << roomID << "power on";

	clients[roomID - 1]->work_mode_received(server->mode, server->Tfloor, server->Tcell, server->Tdefault, server->Wdefault);
	S_P(target[roomID - 1]);
	qDebug() << roomID << "send S_P mode message";
	return;
}

void serverWindow::C_E(int roomID) {
	if (clients[roomID - 1]->run)		
		clients[roomID - 1]->add_a_rec();
	clients[roomID - 1]->power_off();
	qDebug() << roomID << "power off";
}

void serverWindow::C_Q(int roomID) {
	qDebug() << "TODO : Print the reclist of " << roomID;
	server->filled[roomID - 1] = false;
	target[roomID - 1] = nullptr;
	clients[roomID - 1] = new ClientAC();
	qDebug() << roomID << "Quit";
	return;
}

void serverWindow::C_C(int roomID, double Tcurrent) {
	if (clients[roomID - 1]->run == false) {//温度自然变化
		clients[roomID - 1]->Tcurrent = Tcurrent;
		qDebug() << roomID << "set temp current" << Tcurrent;
	}
	return;
}

void serverWindow::C_R(int roomID, int wind) {
	if (clients[roomID - 1]->run)
		clients[roomID - 1]->add_a_rec();
	clients[roomID - 1]->run = false;
	clients[roomID - 1]->set_wind(WIND(wind));
	dispatch();
	qDebug() << roomID << "set wind " << wind;
	return;
}

void serverWindow::C_T(int roomID, double Ttarget) {
	if (clients[roomID - 1]->run)
		clients[roomID - 1]->add_a_rec();
	clients[roomID - 1]->run = false;
	clients[roomID - 1]->set_temp_target(Ttarget);
	dispatch();
	qDebug() << roomID << "set temp target" << Ttarget;
}

void serverWindow::C_G(int cid) {
	clients[cid - 1]->run = false;
	clients[cid - 1]->req = true;
	dispatch();
	qDebug() << cid << "received G";
	return;
}

//send message to client
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
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('H') << hang;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	sock->write(block);
}
void serverWindow::S_A(QTcpSocket* sock) {
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_2);
	out << quint16(0) << quint8('A');
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	sock->write(block);
}

//Answer when buttons were clicked

void serverWindow::on_Bpower_clicked() {
	int sysoff = QString::compare(this->ui.Bpower->text(), QString("关机"));
	if (sysoff == 0) {
		power_off();
	}
	else {
		power_on();
	}
	updateFunction();
}

void serverWindow::power_on() {
	tcpServer = new QTcpServer();
	if (!tcpServer->listen(listenAddr, listenPort)) {
		QMessageBox::warning(NULL, "提示", "TCPServer监听端口失败，请重试。", QMessageBox::Yes | QMessageBox::Cancel);
		return;
	}
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConn()));
	for (int i = 0; i < 4; i++) {
		server->filled[i] = false;
		target[i] = nullptr;
		clients[i] = new ClientAC(i+1, -1);
	}
	this->ui.Ldate->setVisible(true);
	this->ui.Ltime_2->setVisible(true);
	this->ui.Bpower->setText("关机");
	this->ui.Bhalt->setDisabled(true);
	server->work = ON;
	timer->start();
	qDebug() << "Power on : tcp client timer";
}

void serverWindow::power_off() {
	tcpServer->close();
	for (int i = 0; i < 4; i++) {
		server->filled[i] = false;
		target[i] = nullptr;
		clients[i] = nullptr;
	}
	this->ui.Ldate->setVisible(false);
	this->ui.Ltime_2->setVisible(false);
	this->ui.Bpower->setText("开机");
	this->ui.Bhalt->setDisabled(false);
	server->work = OFF;
	timer->stop();
	qDebug() << "Power off : tcp client timer";
}

void serverWindow::on_Bhalt_clicked()
{
	int sysoff = QString::compare(this->ui.Bpower->text(), QString("关机"));
	if (sysoff)
		switch (QMessageBox::information(this, tr("提示"), tr("确认退出?"), tr("确定"), tr("取消"), 0, 1))
		{
		case 0:
			qDebug() << "WRITE DATABASE HERE" << endl;
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

void serverWindow::on_Bcancel_clicked() {
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
	this->ui.Lstate->setText(server->toString());
	for (int i = 0; i < 4; i++) {
		if(server->filled[i]) S_P(target[i]);
	}
}

void serverWindow::on_Bquery_clicked() {
	int roomID = this->ui.spinRoom->value();
	int reclen, i, rid;
	rid = roomID - 1;
	QTableWidgetItem * item;
	
	if (server->filled[rid] == false) {
		reclen = 0;
		this->ui.detailTable->setRowCount(reclen);
	} else {
		reclen = clients[rid]->reclist.size();
		this->ui.detailTable->setRowCount(reclen);
	}
	qDebug() << "Query room " << roomID << "and update detailTable " << reclen;
	if (reclen == 0) return;
	ofstream QueryFile(std::to_string(roomID) + "__" +
		QTime::currentTime().toString("HH-mm-ss").toStdString()+".txt");
	i = 0;
	for (vector<rec>::iterator ip = clients[rid]->reclist.begin(); 
		ip != clients[rid]->reclist.end(); ip++, i++) {
		QueryFile << roomID << ", " << ip->wind 
			<< ", " << ip->start.toString().toStdString()
			<< ", " << ip->end.toString().toStdString() 
			<< ", " << QString::number(ip->elec, 'f', 6).toStdString()
			<< ", " << QString::number(ip->cost, 'f', 6).toStdString() <<"\n";

		item = new QTableWidgetItem(QString::number(roomID));
		this->ui.detailTable->setItem(i, 0, item);
		
		switch (ip->wind) {
		case 1:
			item = new QTableWidgetItem("低速");
			break;
		case 2:
			item = new QTableWidgetItem("中速");
			break;
		case 3:
			item = new QTableWidgetItem("高速");
			break;
		}
		this->ui.detailTable->setItem(i, 1, item);
		
		item = new QTableWidgetItem(QString(ip->start.toString()));
		this->ui.detailTable->setItem(i, 2, item);

		item = new QTableWidgetItem(QString(ip->end.toString()));
		this->ui.detailTable->setItem(i, 3, item);
		
		item = new QTableWidgetItem(QString::number(ip->elec, 'f', 6));
		this->ui.detailTable->setItem(i, 4, item);
		
		item = new QTableWidgetItem(QString::number(ip->cost, 'f', 6));
		this->ui.detailTable->setItem(i, 5, item);
	}
	QueryFile.close();
}

// LOGIC and GUI

//dispatch when req+ or req-
//req+ : C_T() C_R() C_G()
//req- : C_T() S_A()
void serverWindow::dispatch() {
	int req[4] = { 0 };
	double stime[4] = {0};
	int totreq = 0;
	for (int i = 0; i < 4; i++) {
		if (server->filled[i] == true) {
			req[i] = 0; 
			if (clients[i]->req && clients[i]->power) {
				req[i] = (int)clients[i]->wind;
				stime[i] = clients[i]->get_serv_time();
				totreq++;
			}
		}
	}

	if (totreq < 4)
		for (int i = 0; i < 4; i++) {
			if (req[i] > 0 && clients[i]->run == false) {
				//send S_H()
				S_H(target[i], false);
				qDebug() << "S_H " << i << false;
				clients[i]->run = true;
				clients[i]->last_on = QTime::currentTime();
			}
		}

	else if (totreq == 4) {
		int minreq = 3;
		int minnum = 0;
		int ismin;
		int isminlevel[4] = { 0 };
		double maxtime = 0;
		for (int i = 0; i < 4; i++)
			if (minreq > req[i]) minreq = req[i];
		//get the min req level : minreq
		for (int i = 0; i < 4; i++)
			if (minreq == req[i]) {
				minnum++; 
				isminlevel[i] = 1;
				ismin = i;
			}
		//find which is the minreq: isminlevel / minnum
		if (minnum != 1) {
			//ismin is the last min level req
			for(int i=0; i<4; i++)
				if (isminlevel[i] && stime[i] > maxtime) {
					maxtime = stime[i];
					ismin = i;
				}
		}// ismin is the min level and longest time req;
		for (int i = 0; i < 4; i++)
			if (i != ismin) {
				S_H(target[i], false);
				qDebug() << "S_H " << i << false;
				clients[i]->run = true;
				clients[i]->last_on = QTime::currentTime();
			}
			else {
				if (clients[i]->run)
					clients[i]->add_a_rec();
				S_H(target[i], true);
				qDebug() << "S_H " << i << true;
				clients[i]->run = false;
			}
	}
	qDebug() << "dispatch" << req[0] << req[1] << req[2] << req[3] << " | " << (bool)(totreq==4);
}

//updateFunction only work when AC is on and for clients
void serverWindow::updateFunction() {
	//update the working things
	ClientAC * client;
	double flag;
	for (int i = 0; i < 4; i++) {
		if (server->filled[i]) {
			client = clients[i];
			if (client->power == false) continue;
			if (client->run == true) {
				if (client->mode == COOL && client->Tcurrent <= client->Ttarget ||
					client->mode == WARM && client->Tcurrent >= client->Ttarget) {
					//工作中每秒检查一次是否达到目标温度
					S_A(target[i]);
					client->add_a_rec();
					client->run = false;
					client->req = false;
					dispatch();
					continue;
				}
				flag = 1;
				if (client->mode == COOL) flag = -1;
				int wint = (int)client->wind;
				client->elec += server->Espeed[wint];
				client->cost += server->Ecost * server->Espeed[wint];
				client->Tcurrent += flag * server->Espeed[wint];
				if (wint != 0)//工作中每秒发一次 
					S_O(target[i], client->cost, client->Tcurrent);
			}
		}
	}
	updateLabel();
}

//only work the first time of initiation
void serverWindow::initLabel() {
	this->ui.roomTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.detailTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.billTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 5; column++) {
			this->ui.roomTable->item(row, column)->setText("--");
		}
	}
}

//updateLabel only work for roomTable and the two TABs
void serverWindow::updateLabel() {

	// update the time label
	this->ui.Ldate->setText(QDateTime::currentDateTime().toString(QString("yyyy年MM月dd日")));
	this->ui.Ltime_2->setText(QTime::currentTime().toString("时间： HH:mm:ss"));

	// update the RoomTable
	int rowID, colID;
	QTableWidgetItem *tableItem;
	ClientAC *AC;
	if (server->work) {
		for (rowID = 0; rowID < 4; rowID++) {
			//power 运行 0
			if (server->filled[rowID]==false) {
				for (colID = 0; colID < 5; colID++) {
					this->ui.roomTable->item(rowID, colID)->setText("--");
				}
			}
			else {
				AC = clients[rowID];
				if (AC->power)
					this->ui.roomTable->item(rowID, 0)->setText("运行");
				else
					this->ui.roomTable->item(rowID, 0)->setText("关机");
				//req 等待 1
				if (AC->power) {
					if (AC->req && AC->run == false)
						this->ui.roomTable->item(rowID, 1)->setText("是");
					else
						this->ui.roomTable->item(rowID, 1)->setText("否");
				}
				else
					this->ui.roomTable->item(rowID, 1)->setText("--");
				//Tcurrent 温度 2
				if (AC->Tcurrent != -1)
					this->ui.roomTable->item(rowID, 2)->setText(QString::number(AC->Tcurrent));
				else
					this->ui.roomTable->item(rowID, 2)->setText("--");
				//Ttarget 目标 3
				if (AC->power)
					this->ui.roomTable->item(rowID, 3)->setText(QString::number(AC->Ttarget));
				else
					this->ui.roomTable->item(rowID, 3)->setText("--");
				//Wind 风速 4
				if (AC->power == false)
					this->ui.roomTable->item(rowID, 4)->setText("--");

				else {
					if (AC->run == false)
						this->ui.roomTable->item(rowID, 4)->setText("无风");
					else
						switch (AC->wind) {
						case LOW:
							this->ui.roomTable->item(rowID, 4)->setText("低速");
							break;
						case MEDIUM:
							this->ui.roomTable->item(rowID, 4)->setText("中速");
							break;
						case HIGH:
							this->ui.roomTable->item(rowID, 4)->setText("高速");
							break;
						}
				}
			}
		}//work
	}
	else {
		for (rowID = 0; rowID < 4; rowID++)
			for (colID = 0; colID< 5; colID++)
				this->ui.roomTable->item(rowID, colID)->setText("--");
	}

	// update the string
	this->ui.Lstate->setText(server->toString());

	// update the billTable in tag 2
	for (rowID = 0; rowID < 4; rowID++) {
		if (server->filled[rowID] == false) {
			for (colID = 0; colID < 4; colID++)
				this->ui.billTable->item(rowID, colID)->setText("--");
		}
		else {
			this->ui.billTable->item(rowID, 0)->setText(QString::number(rowID+1));
			this->ui.billTable->item(rowID, 1)->setText(clients[rowID]->time_in.toString("HH:mm:ss"));
			this->ui.billTable->item(rowID, 2)->setText(QTime::currentTime().toString("HH:mm:ss"));
			this->ui.billTable->item(rowID, 3)->setText(QString::number(clients[rowID]->cost));
		}
	}
	// The detail table update should be with the Bquery
		//Pass
}