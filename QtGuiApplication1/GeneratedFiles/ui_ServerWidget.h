/********************************************************************************
** Form generated from reading UI file 'ServerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QListView *listView;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QStringLiteral("ServerWidget"));
        ServerWidget->resize(563, 528);
        ServerWidget->setAcceptDrops(true);
        ServerWidget->setLayoutDirection(Qt::RightToLeft);
        pushButton = new QPushButton(ServerWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 80, 91, 81));
        label = new QLabel(ServerWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 210, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        listView = new QListView(ServerWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(40, 11, 256, 291));
        label_2 = new QLabel(ServerWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 21, 161));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setContextMenuPolicy(Qt::NoContextMenu);
        label_2->setAcceptDrops(false);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAutoFillBackground(false);
        label_2->setLineWidth(1);
        label_2->setMidLineWidth(0);
        label_2->setWordWrap(true);
        label_3 = new QLabel(ServerWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 350, 141, 31));
        label_3->setFont(font);
        label_4 = new QLabel(ServerWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 420, 101, 31));
        label_4->setFont(font);
        pushButton_2 = new QPushButton(ServerWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 350, 121, 31));
        pushButton_3 = new QPushButton(ServerWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 420, 101, 31));
        pushButton->raise();
        label->raise();
        listView->raise();
        label_2->raise();
        label_4->raise();
        pushButton_2->raise();
        label_3->raise();
        pushButton_3->raise();

        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QApplication::translate("ServerWidget", "\347\256\241\347\220\206\345\221\230\346\250\241\345\274\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ServerWidget", "ON/OFF", Q_NULLPTR));
        label->setText(QApplication::translate("ServerWidget", "\344\270\255\345\244\256\347\251\272\350\260\203\346\200\273\345\274\200\345\205\263", Q_NULLPTR));
        label_2->setText(QApplication::translate("ServerWidget", "<html><head/><body><p>\344\270\255\345\244\256\347\251\272\350\260\203\347\212\266\346\200\201</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("ServerWidget", "\350\264\271\347\216\207\350\256\276\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("ServerWidget", "\345\267\245\344\275\234\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QString());
        pushButton_3->setText(QApplication::translate("ServerWidget", "\345\206\267/\347\203\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
