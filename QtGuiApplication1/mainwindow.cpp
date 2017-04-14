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
			QMessageBox::warning(NULL, "��ʾ", "TCPServer�����˿�ʧ�ܣ����򼴽��رա�", QMessageBox::Yes | QMessageBox::Cancel);
			this->close();
		}
		else
		connect(tcpServer, SIGNAL(newConnection()), this, SLOT(reply2Connection()));
		//newConnection��ʾ��tcp��������ʱ�ͽ���reply2Connection()�ظ�

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
	out.setVersion(QDataStream::Qt_5_5);//����Qt�汾����ͬ�汾����������ʽ��ͬ

	return;
}
