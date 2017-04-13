/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(400, 300);
        LoginWindow->setAutoFillBackground(false);
        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 260, 101, 28));
        pushButton_2 = new QPushButton(LoginWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 260, 111, 28));
        lineEdit = new QLineEdit(LoginWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 120, 113, 20));
        lineEdit_2 = new QLineEdit(LoginWindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 180, 113, 20));
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 130, 54, 12));
        label->setTextFormat(Qt::AutoText);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 180, 54, 12));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 32, 261, 20));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 220, 71, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("04b_21"));
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label_4->setFont(font1);
        label_4->setOpenExternalLinks(true);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "\347\231\273\345\275\225\347\225\214\351\235\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LoginWindow", "\347\202\271\345\207\273\346\263\250\345\206\214", Q_NULLPTR));
        lineEdit->setText(QString());
        label->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginWindow", "\345\210\206\345\270\203\345\274\217\346\270\251\346\216\247\347\263\273\347\273\237\347\224\250\346\210\267\347\231\273\345\275\225\347\225\214\351\235\242", Q_NULLPTR));
        label_4->setText(QApplication::translate("LoginWindow", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
