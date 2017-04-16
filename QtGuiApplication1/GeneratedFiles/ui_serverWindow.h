/********************************************************************************
** Form generated from reading UI file 'serverWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWindow
{
public:
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

    void setupUi(QWidget *serverWindow)
    {
        if (serverWindow->objectName().isEmpty())
            serverWindow->setObjectName(QStringLiteral("serverWindow"));
        serverWindow->resize(497, 600);
        Wadmin = new QWidget(serverWindow);
        Wadmin->setObjectName(QStringLiteral("Wadmin"));
        Wadmin->setGeometry(QRect(0, 0, 500, 600));
        Wadmin->setMinimumSize(QSize(500, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        Wadmin->setFont(font);
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
        QFont font1;
        font1.setPointSize(12);
        roomTable->setFont(font1);
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
        detailTable->setFont(font1);
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
        __qtablewidgetitem20->setFont(font);
        billTable->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        billTable->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font);
        billTable->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        billTable->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        billTable->setObjectName(QStringLiteral("billTable"));
        billTable->setGeometry(QRect(15, 40, 421, 421));
        tabW->addTab(Pbill, QString());

        retranslateUi(serverWindow);

        tabW->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(serverWindow);
    } // setupUi

    void retranslateUi(QWidget *serverWindow)
    {
        serverWindow->setWindowTitle(QApplication::translate("serverWindow", "serverWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = roomTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("serverWindow", "\350\277\220\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = roomTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("serverWindow", "\347\255\211\345\276\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = roomTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("serverWindow", "\346\270\251\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = roomTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("serverWindow", "\347\233\256\346\240\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = roomTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("serverWindow", "\351\243\216\351\200\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = roomTable->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("serverWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = roomTable->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("serverWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = roomTable->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("serverWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = roomTable->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("serverWindow", "4", Q_NULLPTR));

        const bool __sortingEnabled = roomTable->isSortingEnabled();
        roomTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = roomTable->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("serverWindow", "\346\230\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = roomTable->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("serverWindow", "\345\220\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = roomTable->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("serverWindow", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = roomTable->item(0, 3);
        ___qtablewidgetitem12->setText(QApplication::translate("serverWindow", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = roomTable->item(0, 4);
        ___qtablewidgetitem13->setText(QApplication::translate("serverWindow", "\344\270\255", Q_NULLPTR));
        roomTable->setSortingEnabled(__sortingEnabled);

        Bhalt->setText(QApplication::translate("serverWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        Bpower->setText(QApplication::translate("serverWindow", "\345\205\263\346\234\272", Q_NULLPTR));
        Gmode->setTitle(QApplication::translate("serverWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        Bcool->setText(QApplication::translate("serverWindow", "\345\210\266\345\206\267", Q_NULLPTR));
        Bwarm->setText(QApplication::translate("serverWindow", "\345\210\266\347\203\255", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("serverWindow", "\346\270\251\345\272\246\350\256\276\345\256\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("serverWindow", "\344\270\212\351\231\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("serverWindow", "\344\270\213\351\231\220", Q_NULLPTR));
        label_4->setText(QApplication::translate("serverWindow", "\351\273\230\350\256\244", Q_NULLPTR));
        Bcancel->setText(QApplication::translate("serverWindow", "\345\217\226\346\266\210\346\233\264\346\224\271", Q_NULLPTR));
        Bcommit->setText(QApplication::translate("serverWindow", "\346\217\220\344\272\244\346\233\264\346\224\271", Q_NULLPTR));
        Ldate->setText(QApplication::translate("serverWindow", "YYYY-MM-dd", Q_NULLPTR));
        Ltime_2->setText(QApplication::translate("serverWindow", "HH-mm-ss", Q_NULLPTR));
        Lstate->setText(QApplication::translate("serverWindow", "\345\275\223\345\211\215\345\210\266\345\206\267\357\274\214\346\270\251\345\272\246\350\214\203\345\233\264AA-BB\302\260C\357\274\214\351\273\230\350\256\244CC\302\260C\343\200\202", Q_NULLPTR));
        tabW->setTabText(tabW->indexOf(Pcontrol), QApplication::translate("serverWindow", "\346\216\247\345\210\266\347\225\214\351\235\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = detailTable->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("serverWindow", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = detailTable->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("serverWindow", "\351\243\216\351\200\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = detailTable->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("serverWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = detailTable->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("serverWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = detailTable->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("serverWindow", "\350\203\275\350\200\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = detailTable->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("serverWindow", "\350\264\271\347\224\250", Q_NULLPTR));
        label->setText(QApplication::translate("serverWindow", "\351\200\211\346\213\251\346\210\277\351\227\264\345\217\267\357\274\232", Q_NULLPTR));
        Bquery->setText(QApplication::translate("serverWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        tabW->setTabText(tabW->indexOf(Pdetail), QApplication::translate("serverWindow", "\350\257\246\345\215\225\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = billTable->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("serverWindow", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = billTable->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("serverWindow", "\345\205\245\344\275\217\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = billTable->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("serverWindow", "\345\275\223\345\211\215\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = billTable->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("serverWindow", "\347\264\257\350\256\241\350\264\271\347\224\250", Q_NULLPTR));
        tabW->setTabText(tabW->indexOf(Pbill), QApplication::translate("serverWindow", "\350\264\246\345\215\225\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class serverWindow: public Ui_serverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
