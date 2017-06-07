#pragma once

#include <QWidget>
#include <qtimer.h>
#include "ui_serverWindow.h"
#include "qmessagebox.h"
#include "ConfigAC.h"
#include "ServerAC.h"
#include "ClientAC.h"
#include "qtcpserver.h"
#include "qtcpsocket.h"
#include "qdatetime.h"

extern ROLE role;
extern bool allowin;//for room get in
extern ConfigAC cfg;

class serverWindow : public QWidget
{
	Q_OBJECT

public:
	serverWindow(QWidget *parent = Q_NULLPTR);
	~serverWindow();

private slots:
	void newConn(); //TCP --> readClient
	void readClient(); //TCP --> loop handle the messages
	void updateFunction();
	void updateLabel();

	//admin-Pcontrol
	void on_Bpower_clicked();
	void on_Bcancel_clicked();
	void on_Bcommit_clicked();
	void on_Bhalt_clicked();

	//admin-Pdetail
	void on_Bquery_clicked();

signals:
	void dataRecivedS(); //emit by readClient(), received by updateFunction()
private:
	Ui::serverWindow ui;
	QTimer * timer;

	ServerAC * server;
	ClientAC * clients[4];

	//TCP related
	QTcpServer * tcpServer;
	QTcpSocket* target[4];
	QByteArray block;
	quint16 blockSize;
	quint8 type;
	int listenPort = 6666;
	QHostAddress listenAddr = QHostAddress::Any;
	void power_on();
	void power_off();

	//send message (target socket + info)
	void S_I(QTcpSocket* target, bool success);
	void S_P(QTcpSocket* target);
	void S_O(QTcpSocket* target, double cost, double Tcurrent);
	void S_H(QTcpSocket* target, bool hang);
	void S_A(QTcpSocket* target);

	//cope with received message (cid + info)
	void serverWindow::C_I(int cid, double Tenv, QTcpSocket* client);
	void serverWindow::C_B(int cid);
	void serverWindow::C_E(int cid);
	void serverWindow::C_Q(int cid);
	void serverWindow::C_R(int cid, int wind);
	void serverWindow::C_C(int cid, double Tcurrent);
	void serverWindow::C_T(int cid, double Ttarget);
	void serverWindow::C_G(int cid);

	void dispatch();
	void initLabel();
};
