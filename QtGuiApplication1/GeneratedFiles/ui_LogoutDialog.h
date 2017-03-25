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
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_LogoutDialog
{
public:

    void setupUi(QDialog *LogoutDialog)
    {
        if (LogoutDialog->objectName().isEmpty())
            LogoutDialog->setObjectName(QStringLiteral("LogoutDialog"));
        LogoutDialog->resize(400, 300);

        retranslateUi(LogoutDialog);

        QMetaObject::connectSlotsByName(LogoutDialog);
    } // setupUi

    void retranslateUi(QDialog *LogoutDialog)
    {
        LogoutDialog->setWindowTitle(QApplication::translate("LogoutDialog", "LogoutDialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogoutDialog: public Ui_LogoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOUTDIALOG_H
