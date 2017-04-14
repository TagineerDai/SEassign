/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *Widget;
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
    QPushButton *Btemp;
    QComboBox *Ctemp;
    QLabel *Label_4;
    QLabel *Label_0;
    QLabel *Lwind;
    QLabel *LroomID;
    QLabel *Ltime;
    QLabel *Lconnect;
    QLabel *Label_2;
    QLabel *Lwind_2;
    QWidget *Wadmin;
    QTabWidget *tabW;
    QWidget *Pcontrol;
    QTableWidget *roomTable;
    QPushButton *Bhalt;
    QPushButton *Bpower;
    QGroupBox *Gmode;
    QRadioButton *Bcool;
    QRadioButton *Bwarm;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *CTcell;
    QSpinBox *CTfloor;
    QSpinBox *CTdefault;
    QPushButton *Bcancel;
    QPushButton *Bcommit;
    QLabel *Ldate;
    QLabel *Ltime_2;
    QLabel *Lstate;
    QWidget *Pdetail;
    QTableWidget *detailTable;
    QSpinBox *spinRoom;
    QLabel *label;
    QPushButton *Bquery;
    QWidget *Pbill;
    QTableWidget *billTable;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(501, 603);
        Widget = new QWidget(MainWindowClass);
        Widget->setObjectName(QStringLiteral("Widget"));
        Wroom = new QWidget(Widget);
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
        Gwind->setGeometry(QRect(260, 200, 111, 141));
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
        Gtemp->setGeometry(QRect(20, 200, 231, 71));
        Gtemp->setFont(font1);
        Btemp = new QPushButton(Gtemp);
        Btemp->setObjectName(QStringLiteral("Btemp"));
        Btemp->setGeometry(QRect(120, 20, 101, 41));
        Btemp->setFont(font);
        Ctemp = new QComboBox(Gtemp);
        Ctemp->setObjectName(QStringLiteral("Ctemp"));
        Ctemp->setGeometry(QRect(20, 20, 81, 41));
        Ctemp->setFont(font);
        Label_4 = new QLabel(Wroom);
        Label_4->setObjectName(QStringLiteral("Label_4"));
        Label_4->setGeometry(QRect(200, 60, 111, 31));
        Label_4->setFont(font);
        Label_0 = new QLabel(Wroom);
        Label_0->setObjectName(QStringLiteral("Label_0"));
        Label_0->setGeometry(QRect(200, 100, 111, 31));
        Label_0->setFont(font);
        Lwind = new QLabel(Wroom);
        Lwind->setObjectName(QStringLiteral("Lwind"));
        Lwind->setGeometry(QRect(310, 100, 31, 31));
        Lwind->setFont(font);
        LroomID = new QLabel(Wroom);
        LroomID->setObjectName(QStringLiteral("LroomID"));
        LroomID->setGeometry(QRect(0, 10, 161, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(24);
        LroomID->setFont(font2);
        LroomID->setAlignment(Qt::AlignCenter);
        Ltime = new QLabel(Wroom);
        Ltime->setObjectName(QStringLiteral("Ltime"));
        Ltime->setGeometry(QRect(180, 20, 201, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(13);
        Ltime->setFont(font3);
        Lconnect = new QLabel(Wroom);
        Lconnect->setObjectName(QStringLiteral("Lconnect"));
        Lconnect->setGeometry(QRect(310, 60, 61, 31));
        Lconnect->setFont(font);
        Label_2 = new QLabel(Wroom);
        Label_2->setObjectName(QStringLiteral("Label_2"));
        Label_2->setGeometry(QRect(200, 140, 111, 31));
        Label_2->setFont(font);
        Lwind_2 = new QLabel(Wroom);
        Lwind_2->setObjectName(QStringLiteral("Lwind_2"));
        Lwind_2->setGeometry(QRect(310, 140, 31, 31));
        Lwind_2->setFont(font);
        Wadmin = new QWidget(Widget);
        Wadmin->setObjectName(QStringLiteral("Wadmin"));
        Wadmin->setGeometry(QRect(0, 0, 500, 600));
        Wadmin->setMinimumSize(QSize(500, 600));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(12);
        Wadmin->setFont(font4);
        Wadmin->setAutoFillBackground(true);
        tabW = new QTabWidget(Wadmin);
        tabW->setObjectName(QStringLiteral("tabW"));
        tabW->setGeometry(QRect(20, 20, 461, 561));
        Pcontrol = new QWidget();
        Pcontrol->setObjectName(QStringLiteral("Pcontrol"));
        roomTable = new QTableWidget(Pcontrol);
        if (roomTable->columnCount() < 5)
            roomTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        roomTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        roomTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        roomTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        roomTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        roomTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (roomTable->rowCount() < 4)
            roomTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        roomTable->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        roomTable->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        roomTable->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        roomTable->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        roomTable->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        roomTable->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        roomTable->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        roomTable->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        roomTable->setItem(0, 4, __qtablewidgetitem13);
        roomTable->setObjectName(QStringLiteral("roomTable"));
        roomTable->setGeometry(QRect(30, 350, 401, 153));
        QFont font5;
        font5.setPointSize(12);
        roomTable->setFont(font5);
        roomTable->horizontalHeader()->setDefaultSectionSize(75);
        Bhalt = new QPushButton(Pcontrol);
        Bhalt->setObjectName(QStringLiteral("Bhalt"));
        Bhalt->setGeometry(QRect(30, 30, 81, 31));
        Bpower = new QPushButton(Pcontrol);
        Bpower->setObjectName(QStringLiteral("Bpower"));
        Bpower->setGeometry(QRect(140, 30, 81, 31));
        Gmode = new QGroupBox(Pcontrol);
        Gmode->setObjectName(QStringLiteral("Gmode"));
        Gmode->setGeometry(QRect(270, 180, 161, 141));
        Bcool = new QRadioButton(Gmode);
        Bcool->setObjectName(QStringLiteral("Bcool"));
        Bcool->setGeometry(QRect(40, 30, 101, 41));
        Bcool->setChecked(true);
        Bwarm = new QRadioButton(Gmode);
        Bwarm->setObjectName(QStringLiteral("Bwarm"));
        Bwarm->setGeometry(QRect(40, 70, 101, 41));
        Bcool->raise();
        Bwarm->raise();
        groupBox = new QGroupBox(Pcontrol);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 180, 201, 141));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 30, 41, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 41, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 41, 21));
        CTcell = new QSpinBox(groupBox);
        CTcell->setObjectName(QStringLiteral("CTcell"));
        CTcell->setGeometry(QRect(80, 30, 71, 22));
        CTfloor = new QSpinBox(groupBox);
        CTfloor->setObjectName(QStringLiteral("CTfloor"));
        CTfloor->setGeometry(QRect(80, 70, 71, 22));
        CTdefault = new QSpinBox(groupBox);
        CTdefault->setObjectName(QStringLiteral("CTdefault"));
        CTdefault->setGeometry(QRect(80, 110, 71, 22));
        Bcancel = new QPushButton(Pcontrol);
        Bcancel->setObjectName(QStringLiteral("Bcancel"));
        Bcancel->setGeometry(QRect(30, 80, 81, 31));
        Bcommit = new QPushButton(Pcontrol);
        Bcommit->setObjectName(QStringLiteral("Bcommit"));
        Bcommit->setGeometry(QRect(140, 80, 81, 31));
        Ldate = new QLabel(Pcontrol);
        Ldate->setObjectName(QStringLiteral("Ldate"));
        Ldate->setGeometry(QRect(270, 30, 161, 31));
        Ltime_2 = new QLabel(Pcontrol);
        Ltime_2->setObjectName(QStringLiteral("Ltime_2"));
        Ltime_2->setGeometry(QRect(270, 80, 161, 31));
        Lstate = new QLabel(Pcontrol);
        Lstate->setObjectName(QStringLiteral("Lstate"));
        Lstate->setGeometry(QRect(40, 130, 371, 31));
        tabW->addTab(Pcontrol, QString());
        Pdetail = new QWidget();
        Pdetail->setObjectName(QStringLiteral("Pdetail"));
        detailTable = new QTableWidget(Pdetail);
        if (detailTable->columnCount() < 6)
            detailTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        detailTable->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        detailTable->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        detailTable->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        detailTable->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        detailTable->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        detailTable->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        detailTable->setObjectName(QStringLiteral("detailTable"));
        detailTable->setGeometry(QRect(10, 20, 431, 411));
        detailTable->setFont(font5);
        detailTable->horizontalHeader()->setDefaultSectionSize(70);
        spinRoom = new QSpinBox(Pdetail);
        spinRoom->setObjectName(QStringLiteral("spinRoom"));
        spinRoom->setGeometry(QRect(171, 461, 51, 31));
        spinRoom->setMinimum(1);
        spinRoom->setMaximum(4);
        label = new QLabel(Pdetail);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 455, 121, 41));
        Bquery = new QPushButton(Pdetail);
        Bquery->setObjectName(QStringLiteral("Bquery"));
        Bquery->setGeometry(QRect(264, 462, 81, 31));
        tabW->addTab(Pdetail, QString());
        Pbill = new QWidget();
        Pbill->setObjectName(QStringLiteral("Pbill"));
        billTable = new QTableWidget(Pbill);
        if (billTable->columnCount() < 4)
            billTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font4);
        billTable->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font4);
        billTable->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font4);
        billTable->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font4);
        billTable->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        billTable->setObjectName(QStringLiteral("billTable"));
        billTable->setGeometry(QRect(15, 40, 421, 421));
        tabW->addTab(Pbill, QString());
        MainWindowClass->setCentralWidget(Widget);

        retranslateUi(MainWindowClass);

        tabW->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "\345\244\247\345\236\213\345\210\206\345\270\203\345\274\217\346\270\251\346\216\247\347\263\273\347\273\237", Q_NULLPTR));
        Label_3->setText(QApplication::translate("MainWindowClass", "\347\264\257\350\256\241\350\264\271\347\224\250", Q_NULLPTR));
        Label_5->setText(QApplication::translate("MainWindowClass", "\345\275\223\345\211\215\345\256\244\346\270\251", Q_NULLPTR));
        Bon->setText(QApplication::translate("MainWindowClass", "\345\274\200\346\234\272", Q_NULLPTR));
        Gwind->setTitle(QApplication::translate("MainWindowClass", "\351\243\216\351\200\237\351\200\211\346\213\251", Q_NULLPTR));
        W3->setText(QApplication::translate("MainWindowClass", "\351\253\230\351\200\237", Q_NULLPTR));
        W2->setText(QApplication::translate("MainWindowClass", "\344\270\255\351\200\237", Q_NULLPTR));
        W1->setText(QApplication::translate("MainWindowClass", "\344\275\216\351\200\237", Q_NULLPTR));
        Bcout->setText(QApplication::translate("MainWindowClass", "\351\200\200\346\210\277", Q_NULLPTR));
        Label_1->setText(QApplication::translate("MainWindowClass", "\347\233\256\346\240\207\346\270\251\345\272\246", Q_NULLPTR));
        Gtemp->setTitle(QApplication::translate("MainWindowClass", "\346\270\251\345\272\246\346\233\264\346\224\271", Q_NULLPTR));
        Btemp->setText(QApplication::translate("MainWindowClass", "\346\217\220\344\272\244\346\233\264\346\224\271", Q_NULLPTR));
        Label_4->setText(QApplication::translate("MainWindowClass", "\347\275\221\347\273\234\347\212\266\345\206\265\357\274\232", Q_NULLPTR));
        Label_0->setText(QApplication::translate("MainWindowClass", "\345\275\223\345\211\215\351\243\216\351\200\237\357\274\232", Q_NULLPTR));
        Lwind->setText(QApplication::translate("MainWindowClass", "\344\270\255", Q_NULLPTR));
        LroomID->setText(QApplication::translate("MainWindowClass", "1\345\217\267\346\210\277\351\227\264", Q_NULLPTR));
        Ltime->setText(QApplication::translate("MainWindowClass", "YYYY-MM-dd HH:mm:ss", Q_NULLPTR));
        Lconnect->setText(QApplication::translate("MainWindowClass", "\346\255\243\345\270\270", Q_NULLPTR));
        Label_2->setText(QApplication::translate("MainWindowClass", "\347\255\211\345\276\205\350\260\203\345\272\246\357\274\232", Q_NULLPTR));
        Lwind_2->setText(QApplication::translate("MainWindowClass", "\346\230\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = roomTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindowClass", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = roomTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindowClass", "\347\255\211\345\276\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = roomTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindowClass", "\346\270\251\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = roomTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindowClass", "\347\233\256\346\240\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = roomTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindowClass", "\351\243\216\351\200\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = roomTable->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindowClass", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = roomTable->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindowClass", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = roomTable->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindowClass", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = roomTable->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindowClass", "4", Q_NULLPTR));

        const bool __sortingEnabled = roomTable->isSortingEnabled();
        roomTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = roomTable->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindowClass", "\346\230\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = roomTable->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindowClass", "\345\220\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = roomTable->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindowClass", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = roomTable->item(0, 3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindowClass", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = roomTable->item(0, 4);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindowClass", "\344\270\255", Q_NULLPTR));
        roomTable->setSortingEnabled(__sortingEnabled);

        Bhalt->setText(QApplication::translate("MainWindowClass", "\351\200\200\345\207\272", Q_NULLPTR));
        Bpower->setText(QApplication::translate("MainWindowClass", "\345\205\263\346\234\272", Q_NULLPTR));
        Gmode->setTitle(QApplication::translate("MainWindowClass", "\346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        Bcool->setText(QApplication::translate("MainWindowClass", "\345\210\266\345\206\267", Q_NULLPTR));
        Bwarm->setText(QApplication::translate("MainWindowClass", "\345\210\266\347\203\255", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "\346\270\251\345\272\246\350\256\276\345\256\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowClass", "\344\270\212\351\231\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindowClass", "\344\270\213\351\231\220", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowClass", "\351\273\230\350\256\244", Q_NULLPTR));
        Bcancel->setText(QApplication::translate("MainWindowClass", "\345\217\226\346\266\210\346\233\264\346\224\271", Q_NULLPTR));
        Bcommit->setText(QApplication::translate("MainWindowClass", "\346\217\220\344\272\244\346\233\264\346\224\271", Q_NULLPTR));
        Ldate->setText(QApplication::translate("MainWindowClass", "YYYY-MM-dd", Q_NULLPTR));
        Ltime_2->setText(QApplication::translate("MainWindowClass", "HH-mm-ss", Q_NULLPTR));
        Lstate->setText(QApplication::translate("MainWindowClass", "\345\275\223\345\211\215\345\210\266\345\206\267\357\274\214\346\270\251\345\272\246\350\214\203\345\233\264AA-BB\302\260C\357\274\214\351\273\230\350\256\244CC\302\260C\343\200\202", Q_NULLPTR));
        tabW->setTabText(tabW->indexOf(Pcontrol), QApplication::translate("MainWindowClass", "\346\216\247\345\210\266\347\225\214\351\235\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = detailTable->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindowClass", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = detailTable->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindowClass", "\351\243\216\351\200\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = detailTable->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindowClass", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = detailTable->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindowClass", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = detailTable->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindowClass", "\350\203\275\350\200\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = detailTable->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindowClass", "\350\264\271\347\224\250", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowClass", "\351\200\211\346\213\251\346\210\277\351\227\264\345\217\267\357\274\232", Q_NULLPTR));
        Bquery->setText(QApplication::translate("MainWindowClass", "\346\237\245\350\257\242", Q_NULLPTR));
        tabW->setTabText(tabW->indexOf(Pdetail), QApplication::translate("MainWindowClass", "\350\257\246\345\215\225\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = billTable->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindowClass", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = billTable->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindowClass", "\345\205\245\344\275\217\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = billTable->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindowClass", "\345\275\223\345\211\215\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = billTable->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindowClass", "\347\264\257\350\256\241\350\264\271\347\224\250", Q_NULLPTR));
        tabW->setTabText(tabW->indexOf(Pbill), QApplication::translate("MainWindowClass", "\350\264\246\345\215\225\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
