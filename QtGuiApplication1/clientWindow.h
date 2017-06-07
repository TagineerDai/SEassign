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

extern int room; //room id
extern double Tinit; //the input env 
extern ConfigAC cfg;
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
	void initLabel();
	void updateLabel();
	//room-vindow
	void on_Bon_clicked();
	void on_Bcout_clicked();
	void on_Bsubmit_clicked();
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
	QHostAddress hostAddr = QHostAddress("127.0.0.1");
	Ui::clientWindow ui;
	int windbtn = 0;
	QTcpSocket *tcpSocket;
	ClientAC client;
	QTimer * timer, * auto_timer;
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
