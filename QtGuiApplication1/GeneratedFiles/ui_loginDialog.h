/********************************************************************************
** Form generated from reading UI file 'loginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QTabWidget *roleTab;
    QWidget *admin;
    QLabel *L1user;
    QLabel *L1pwd;
    QLineEdit *adminuser;
    QLineEdit *adminpwd;
    QWidget *user;
    QLabel *L2user;
    QLabel *L2pwd;
    QLineEdit *roompwd;
    QLineEdit *roomuser;
    QLabel *loginLabel;
    QPushButton *Bhelp;
    QPushButton *Blogin;
    QPushButton *Bcancel;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(344, 228);
        roleTab = new QTabWidget(loginDialog);
        roleTab->setObjectName(QStringLiteral("roleTab"));
        roleTab->setGeometry(QRect(20, 70, 311, 111));
        roleTab->setAcceptDrops(true);
        roleTab->setTabBarAutoHide(false);
        admin = new QWidget();
        admin->setObjectName(QStringLiteral("admin"));
        L1user = new QLabel(admin);
        L1user->setObjectName(QStringLiteral("L1user"));
        L1user->setGeometry(QRect(20, 20, 54, 12));
        L1pwd = new QLabel(admin);
        L1pwd->setObjectName(QStringLiteral("L1pwd"));
        L1pwd->setGeometry(QRect(20, 50, 54, 12));
        adminuser = new QLineEdit(admin);
        adminuser->setObjectName(QStringLiteral("adminuser"));
        adminuser->setGeometry(QRect(80, 15, 113, 20));
        adminpwd = new QLineEdit(admin);
        adminpwd->setObjectName(QStringLiteral("adminpwd"));
        adminpwd->setGeometry(QRect(80, 45, 113, 20));
        roleTab->addTab(admin, QString());
        user = new QWidget();
        user->setObjectName(QStringLiteral("user"));
        L2user = new QLabel(user);
        L2user->setObjectName(QStringLiteral("L2user"));
        L2user->setGeometry(QRect(20, 20, 54, 12));
        L2pwd = new QLabel(user);
        L2pwd->setObjectName(QStringLiteral("L2pwd"));
        L2pwd->setGeometry(QRect(20, 50, 54, 12));
        roompwd = new QLineEdit(user);
        roompwd->setObjectName(QStringLiteral("roompwd"));
        roompwd->setGeometry(QRect(80, 45, 113, 20));
        roomuser = new QLineEdit(user);
        roomuser->setObjectName(QStringLiteral("roomuser"));
        roomuser->setGeometry(QRect(80, 15, 113, 20));
        roleTab->addTab(user, QString());
        loginLabel = new QLabel(loginDialog);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(120, 20, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(22);
        loginLabel->setFont(font);
        Bhelp = new QPushButton(loginDialog);
        Bhelp->setObjectName(QStringLiteral("Bhelp"));
        Bhelp->setGeometry(QRect(20, 190, 75, 23));
        Blogin = new QPushButton(loginDialog);
        Blogin->setObjectName(QStringLiteral("Blogin"));
        Blogin->setGeometry(QRect(160, 190, 75, 23));
        Bcancel = new QPushButton(loginDialog);
        Bcancel->setObjectName(QStringLiteral("Bcancel"));
        Bcancel->setGeometry(QRect(250, 190, 75, 23));

        retranslateUi(loginDialog);
        QObject::connect(Bcancel, SIGNAL(clicked()), loginDialog, SLOT(reject()));

        roleTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "loginDialog", Q_NULLPTR));
        L1user->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        L1pwd->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        roleTab->setTabText(roleTab->indexOf(admin), QApplication::translate("loginDialog", "\347\256\241\347\220\206\345\221\230\347\231\273\351\231\206", Q_NULLPTR));
        L2user->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        L2pwd->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        roleTab->setTabText(roleTab->indexOf(user), QApplication::translate("loginDialog", "\346\210\277\351\227\264\347\231\273\351\231\206", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("loginDialog", "\347\263\273\347\273\237\347\231\273\351\231\206", Q_NULLPTR));
        Bhelp->setText(QApplication::translate("loginDialog", "\345\270\256\345\212\251", Q_NULLPTR));
        Blogin->setText(QApplication::translate("loginDialog", "\347\231\273\351\231\206", Q_NULLPTR));
        Bcancel->setText(QApplication::translate("loginDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
