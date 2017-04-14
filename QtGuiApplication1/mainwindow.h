#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "ConfigAC.h"
#include "ServerAC.h"
#include "ClientAC.h"
#include "qtimer.h"
#include "qtcpsocket.h"
#include "qtcpserver.h"
#include "qdatastream.h"
extern ROLE role;
extern ServerAC server;
extern ClientAC client;
extern ClientArray clients;
extern ConfigAC cfg;
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QTimer * timer;
	MainWindow(QWidget *parent = Q_NULLPTR);
	QByteArray block; //data to send
	quint16 tcpPort; //port

	QTcpServer *tcpServer; //Only for server
	
	QTcpSocket tcpSocket; //For connection
	void initWidget();
private slots:
	void reply2Connection();
private:
	Ui::MainWindowClass ui;
};
