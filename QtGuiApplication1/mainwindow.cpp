#include "mainwindow.h"
#include "qdebug.h"
#include "qmessagebox.h"
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void MainWindow::initWidget() {
	qDebug() << "ROLE ==" << role;
	qDebug() << "MainWindow--updateWidget()";
	switch (role) {
	case ADMIN:
		this->setGeometry(100, 100, 500, 600);
		this->ui.Widget->setGeometry(0, 0, 500, 600);
		this->ui.Wroom->hide();
		this->ui.Wadmin->setVisible(true);

		//InitTheTcpServer
		tcpPort = cfg.port;
		tcpServer = new QTcpServer(this);

		if (!tcpServer->listen(QHostAddress(QHostAddress::LocalHost), 53))
		{
			QMessageBox::warning(NULL, "提示", "TCPServer监听端口失败，程序即将关闭。", QMessageBox::Yes | QMessageBox::Cancel);
			this->close();
		}
		else
		connect(tcpServer, SIGNAL(newConnection()), this, SLOT(reply2Connection()));
		//newConnection表示当tcp有新连接时就交由reply2Connection()回复

		break;
	case ROOM:
		this->setGeometry(100, 100, 400, 350);
		this->ui.Widget->setGeometry(0, 0, 400, 350);
		this->ui.Wadmin->hide();
		this->ui.Wroom->setVisible(true);
		break;
	}
}

void MainWindow::reply2Connection() {
	//if()
	//init the out stream
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_5);//设置Qt版本，不同版本的数据流格式不同

	return;
}
