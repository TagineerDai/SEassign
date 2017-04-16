#pragma once

#include "ui_clientWindow.h"
#include "ConfigAC.h"
#include "ClientAC.h"
#include "ServerAC.h"
#include "Request.h"
#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <QTCPSocket>
#include <QByteArray>
#include <QString>
#include <cstring>

extern int room;
extern double Tinit;

class clientWindow : public QWidget
{
	Q_OBJECT

public:
	clientWindow(QWidget *parent = Q_NULLPTR);
	~clientWindow();
private slots:
	//general logic + gui init
	void updateFunction();
	//general gui
	void updateLabel();
	//room-vindow
	void on_Bon_clicked();
	void on_Bcout_clicked();
	void on_Btemp_clicked();
	void on_W1_clicked();
	void on_W2_clicked();
	void on_W3_clicked();
	//tcp
	void connected();
	void clientRead();
	void displayError(QAbstractSocket::SocketError socketError);
signals:
	void dataRecived();
private:
	int hostPort = 6666;
	QHostAddress hostAddr = QHostAddress::LocalHost;
	Ui::clientWindow ui;
	QTcpSocket *tcpSocket;
	ClientAC client;
	QTimer * timer;
	QByteArray block; //¿éÐÅÏ¢
	quint8 type; //ÃüÁî×Ö
	quint16 blockSize;
	void C_I();
	void C_B();
	void C_E();
	void C_Q();
	void C_T();
	void C_G();
	void C_C();
	void C_R();
};
