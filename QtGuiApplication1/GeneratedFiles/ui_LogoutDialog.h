/********************************************************************************
** Form generated from reading UI file 'LogoutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOUTDIALOG_H
#define UI_LOGOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_LogoutDialog
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LogoutDialog)
    {
        if (LogoutDialog->objectName().isEmpty())
            LogoutDialog->setObjectName(QStringLiteral("LogoutDialog"));
        LogoutDialog->resize(400, 300);
        textBrowser = new QTextBrowser(LogoutDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(-5, 0, 411, 192));
        label = new QLabel(LogoutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 210, 91, 16));
        buttonBox = new QDialogButtonBox(LogoutDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 231, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(LogoutDialog);

        QMetaObject::connectSlotsByName(LogoutDialog);
    } // setupUi

    void retranslateUi(QDialog *LogoutDialog)
    {
        LogoutDialog->setWindowTitle(QApplication::translate("LogoutDialog", "LogoutDialog", Q_NULLPTR));
        label->setText(QApplication::translate("LogoutDialog", "\347\241\256\350\256\244\351\200\200\345\207\272\357\274\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogoutDialog: public Ui_LogoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOUTDIALOG_H
