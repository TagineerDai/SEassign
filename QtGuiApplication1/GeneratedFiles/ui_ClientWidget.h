/********************************************************************************
** Form generated from reading UI file 'ClientWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *TemperatureSet;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_12;
    QTextBrowser *textBrowser;
    QDial *dial;
    QLabel *label_13;
    QLCDNumber *lcdNumber_2;
    QLabel *label_14;
    QLCDNumber *lcdNumber_3;
    QLabel *label_15;
    QTextBrowser *textBrowser_2;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->setWindowModality(Qt::WindowModal);
        ClientWidget->resize(515, 584);
        lcdNumber = new QLCDNumber(ClientWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(120, 200, 71, 41));
        lcdNumber->setProperty("intValue", QVariant(24));
        label = new QLabel(ClientWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 190, 91, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 200, 51, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Hebrew"));
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_3 = new QLabel(ClientWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 190, 111, 71));
        label_3->setFont(font);
        label_4 = new QLabel(ClientWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 200, 51, 51));
        label_4->setFont(font1);
        label_5 = new QLabel(ClientWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 340, 91, 71));
        label_5->setFont(font);
        TemperatureSet = new QSpinBox(ClientWidget);
        TemperatureSet->setObjectName(QStringLiteral("TemperatureSet"));
        TemperatureSet->setGeometry(QRect(370, 190, 91, 61));
        TemperatureSet->setSpecialValueText(QStringLiteral(""));
        TemperatureSet->setKeyboardTracking(false);
        TemperatureSet->setProperty("showGroupSeparator", QVariant(false));
        TemperatureSet->setMinimum(16);
        TemperatureSet->setMaximum(30);
        TemperatureSet->setValue(25);
        TemperatureSet->setDisplayIntegerBase(10);
        label_6 = new QLabel(ClientWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(470, 340, 91, 71));
        label_6->setFont(font);
        label_7 = new QLabel(ClientWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 300, 61, 31));
        label_8 = new QLabel(ClientWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(380, 300, 31, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Century"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        label_8->setFont(font2);
        label_9 = new QLabel(ClientWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(440, 410, 31, 41));
        label_9->setFont(font2);
        label_10 = new QLabel(ClientWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(330, 410, 31, 41));
        label_10->setFont(font2);
        label_11 = new QLabel(ClientWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(240, 500, 91, 71));
        label_11->setFont(font);
        pushButton_2 = new QPushButton(ClientWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 530, 81, 51));
        pushButton_3 = new QPushButton(ClientWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 480, 81, 51));
        pushButton = new QPushButton(ClientWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 330, 121, 111));
        label_12 = new QLabel(ClientWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(90, 420, 91, 71));
        label_12->setFont(font);
        textBrowser = new QTextBrowser(ClientWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 501, 141));
        dial = new QDial(ClientWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(339, 350, 111, 64));
        label_13 = new QLabel(ClientWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 10, 121, 16));
        lcdNumber_2 = new QLCDNumber(ClientWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(90, 0, 71, 31));
        lcdNumber_2->setProperty("intValue", QVariant(1));
        label_14 = new QLabel(ClientWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(180, 10, 54, 12));
        lcdNumber_3 = new QLCDNumber(ClientWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(240, 0, 71, 31));
        label_15 = new QLabel(ClientWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(340, 10, 54, 12));
        textBrowser_2 = new QTextBrowser(ClientWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(400, 0, 111, 31));

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "\347\224\250\346\210\267\346\250\241\345\274\217", Q_NULLPTR));
        label->setText(QApplication::translate("ClientWidget", "\345\275\223\345\211\215\345\256\244\346\270\251", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClientWidget", "\342\204\203", Q_NULLPTR));
        label_3->setText(QApplication::translate("ClientWidget", "\347\233\256\346\240\207\346\270\251\345\272\246\350\256\276\345\256\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ClientWidget", "\342\204\203", Q_NULLPTR));
        label_5->setText(QApplication::translate("ClientWidget", "\351\243\216\351\200\237", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        TemperatureSet->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        TemperatureSet->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label_6->setText(QApplication::translate("ClientWidget", "\347\272\247", Q_NULLPTR));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("ClientWidget", "H", Q_NULLPTR));
        label_9->setText(QApplication::translate("ClientWidget", "L", Q_NULLPTR));
        label_10->setText(QApplication::translate("ClientWidget", "M", Q_NULLPTR));
        label_11->setText(QApplication::translate("ClientWidget", "\345\267\245\344\275\234\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ClientWidget", "\345\210\266\346\232\226", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ClientWidget", "\345\210\266\345\206\267", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("ClientWidget", "<html><head/><body><p>\345\274\200\345\205\263</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("ClientWidget", "ON/OFF", Q_NULLPTR));
        label_12->setText(QApplication::translate("ClientWidget", "\347\224\265\346\272\220\345\274\200\345\205\263", Q_NULLPTR));
        label_13->setText(QApplication::translate("ClientWidget", "\345\275\223\345\211\215\346\210\277\351\227\264\345\217\267\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("ClientWidget", "\345\275\223\345\211\215\344\275\231\351\242\235\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("ClientWidget", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
