/********************************************************************************
** Form generated from reading UI file 'clientWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWindow
{
public:
    QWidget *Wroom;
    QLabel *Label_3;
    QLCDNumber *Ncost;
    QLabel *Label_5;
    QPushButton *Bon;
    QGroupBox *Gwind;
    QRadioButton *W3;
    QRadioButton *W2;
    QRadioButton *W1;
    QPushButton *Bcout;
    QLabel *Label_1;
    QLCDNumber *NTnow;
    QLCDNumber *NTtarget;
    QGroupBox *Gtemp;
    QSpinBox *STemp;
    QLabel *Label_4;
    QLabel *Label_0;
    QLabel *LWcurrent;
    QLabel *LroomID;
    QLabel *Ltime;
    QLabel *LWtarget;
    QLabel *Label_2;
    QLabel *Lwait;
    QPushButton *Bsubmit;

    void setupUi(QWidget *clientWindow)
    {
        if (clientWindow->objectName().isEmpty())
            clientWindow->setObjectName(QStringLiteral("clientWindow"));
        clientWindow->resize(400, 350);
        Wroom = new QWidget(clientWindow);
        Wroom->setObjectName(QStringLiteral("Wroom"));
        Wroom->setGeometry(QRect(0, 0, 400, 350));
        Wroom->setMinimumSize(QSize(400, 350));
        Wroom->setMaximumSize(QSize(410, 360));
        Wroom->setAutoFillBackground(true);
        Label_3 = new QLabel(Wroom);
        Label_3->setObjectName(QStringLiteral("Label_3"));
        Label_3->setGeometry(QRect(20, 60, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        Label_3->setFont(font);
        Ncost = new QLCDNumber(Wroom);
        Ncost->setObjectName(QStringLiteral("Ncost"));
        Ncost->setGeometry(QRect(110, 60, 71, 31));
        Label_5 = new QLabel(Wroom);
        Label_5->setObjectName(QStringLiteral("Label_5"));
        Label_5->setGeometry(QRect(20, 100, 91, 31));
        Label_5->setFont(font);
        Bon = new QPushButton(Wroom);
        Bon->setObjectName(QStringLiteral("Bon"));
        Bon->setGeometry(QRect(40, 290, 81, 41));
        Bon->setFont(font);
        Gwind = new QGroupBox(Wroom);
        Gwind->setObjectName(QStringLiteral("Gwind"));
        Gwind->setGeometry(QRect(260, 190, 111, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Gwind->setFont(font1);
        Gwind->setFocusPolicy(Qt::NoFocus);
        Gwind->setFlat(false);
        Gwind->setCheckable(false);
        W3 = new QRadioButton(Gwind);
        W3->setObjectName(QStringLiteral("W3"));
        W3->setGeometry(QRect(20, 20, 89, 31));
        W3->setFont(font);
        W2 = new QRadioButton(Gwind);
        W2->setObjectName(QStringLiteral("W2"));
        W2->setGeometry(QRect(20, 60, 89, 31));
        W2->setFont(font);
        W2->setChecked(true);
        W1 = new QRadioButton(Gwind);
        W1->setObjectName(QStringLiteral("W1"));
        W1->setGeometry(QRect(20, 100, 89, 31));
        W1->setFont(font);
        Bcout = new QPushButton(Wroom);
        Bcout->setObjectName(QStringLiteral("Bcout"));
        Bcout->setGeometry(QRect(150, 290, 81, 41));
        Bcout->setFont(font);
        Label_1 = new QLabel(Wroom);
        Label_1->setObjectName(QStringLiteral("Label_1"));
        Label_1->setGeometry(QRect(20, 140, 91, 31));
        Label_1->setFont(font);
        NTnow = new QLCDNumber(Wroom);
        NTnow->setObjectName(QStringLiteral("NTnow"));
        NTnow->setGeometry(QRect(110, 100, 71, 31));
        NTnow->setProperty("intValue", QVariant(1));
        NTtarget = new QLCDNumber(Wroom);
        NTtarget->setObjectName(QStringLiteral("NTtarget"));
        NTtarget->setGeometry(QRect(110, 140, 71, 31));
        NTtarget->setProperty("intValue", QVariant(1));
        Gtemp = new QGroupBox(Wroom);
        Gtemp->setObjectName(QStringLiteral("Gtemp"));
        Gtemp->setGeometry(QRect(150, 190, 101, 71));
        Gtemp->setFont(font1);
        STemp = new QSpinBox(Gtemp);
        STemp->setObjectName(QStringLiteral("STemp"));
        STemp->setGeometry(QRect(20, 25, 61, 31));
        QFont font2;
        font2.setPointSize(12);
        STemp->setFont(font2);
        STemp->setMinimum(18);
        STemp->setMaximum(30);
        Label_4 = new QLabel(Wroom);
        Label_4->setObjectName(QStringLiteral("Label_4"));
        Label_4->setGeometry(QRect(200, 140, 111, 31));
        Label_4->setFont(font);
        Label_0 = new QLabel(Wroom);
        Label_0->setObjectName(QStringLiteral("Label_0"));
        Label_0->setGeometry(QRect(200, 100, 111, 31));
        Label_0->setFont(font);
        LWcurrent = new QLabel(Wroom);
        LWcurrent->setObjectName(QStringLiteral("LWcurrent"));
        LWcurrent->setGeometry(QRect(310, 100, 61, 31));
        LWcurrent->setFont(font);
        LroomID = new QLabel(Wroom);
        LroomID->setObjectName(QStringLiteral("LroomID"));
        LroomID->setGeometry(QRect(0, 10, 161, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(24);
        LroomID->setFont(font3);
        LroomID->setAlignment(Qt::AlignCenter);
        Ltime = new QLabel(Wroom);
        Ltime->setObjectName(QStringLiteral("Ltime"));
        Ltime->setGeometry(QRect(140, 20, 241, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(13);
        Ltime->setFont(font4);
        LWtarget = new QLabel(Wroom);
        LWtarget->setObjectName(QStringLiteral("LWtarget"));
        LWtarget->setGeometry(QRect(310, 140, 61, 31));
        LWtarget->setFont(font);
        Label_2 = new QLabel(Wroom);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setGeometry(QRect(200, 60, 111, 31));
        Label_2->setFont(font);
        Lwait = new QLabel(Wroom);
        Lwait->setObjectName(QStringLiteral("Lwait"));
        Lwait->setGeometry(QRect(310, 60, 31, 31));
        Lwait->setFont(font);
        Bsubmit = new QPushButton(Wroom);
        Bsubmit->setObjectName(QStringLiteral("Bsubmit"));
        Bsubmit->setGeometry(QRect(30, 210, 101, 41));
        Bsubmit->setFont(font);

        retranslateUi(clientWindow);

        QMetaObject::connectSlotsByName(clientWindow);
    } // setupUi

    void retranslateUi(QWidget *clientWindow)
    {
        clientWindow->setWindowTitle(QApplication::translate("clientWindow", "clientWindow", Q_NULLPTR));
        Label_3->setText(QApplication::translate("clientWindow", "\347\264\257\350\256\241\350\264\271\347\224\250", Q_NULLPTR));
        Label_5->setText(QApplication::translate("clientWindow", "\345\275\223\345\211\215\345\256\244\346\270\251", Q_NULLPTR));
        Bon->setText(QApplication::translate("clientWindow", "\345\274\200\346\234\272", Q_NULLPTR));
        Gwind->setTitle(QApplication::translate("clientWindow", "\351\243\216\351\200\237\351\200\211\346\213\251", Q_NULLPTR));
        W3->setText(QApplication::translate("clientWindow", "\351\253\230\351\200\237", Q_NULLPTR));
        W2->setText(QApplication::translate("clientWindow", "\344\270\255\351\200\237", Q_NULLPTR));
        W1->setText(QApplication::translate("clientWindow", "\344\275\216\351\200\237", Q_NULLPTR));
        Bcout->setText(QApplication::translate("clientWindow", "\351\200\200\346\210\277", Q_NULLPTR));
        Label_1->setText(QApplication::translate("clientWindow", "\347\233\256\346\240\207\346\270\251\345\272\246", Q_NULLPTR));
        Gtemp->setTitle(QApplication::translate("clientWindow", "\346\270\251\345\272\246\346\233\264\346\224\271", Q_NULLPTR));
        Label_4->setText(QApplication::translate("clientWindow", "\347\233\256\346\240\207\351\243\216\351\200\237\357\274\232", Q_NULLPTR));
        Label_0->setText(QApplication::translate("clientWindow", "\345\275\223\345\211\215\351\243\216\351\200\237\357\274\232", Q_NULLPTR));
        LWcurrent->setText(QApplication::translate("clientWindow", "\346\227\240", Q_NULLPTR));
        LroomID->setText(QApplication::translate("clientWindow", "1\345\217\267\346\210\277\351\227\264", Q_NULLPTR));
        Ltime->setText(QApplication::translate("clientWindow", "YYYY-MM-dd HH:mm:ss", Q_NULLPTR));
        LWtarget->setText(QApplication::translate("clientWindow", "\344\270\255", Q_NULLPTR));
        Label_2->setText(QApplication::translate("clientWindow", "\347\255\211\345\276\205\350\260\203\345\272\246\357\274\232", Q_NULLPTR));
        Lwait->setText(QApplication::translate("clientWindow", "\346\230\257", Q_NULLPTR));
        Bsubmit->setText(QApplication::translate("clientWindow", "\346\217\220\344\272\244\346\233\264\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clientWindow: public Ui_clientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
