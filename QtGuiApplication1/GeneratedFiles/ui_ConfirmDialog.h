/********************************************************************************
** Form generated from reading UI file 'ConfirmDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDIALOG_H
#define UI_CONFIRMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDialog
{
public:
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfirmDialog)
    {
        if (ConfirmDialog->objectName().isEmpty())
            ConfirmDialog->setObjectName(QStringLiteral("ConfirmDialog"));
        ConfirmDialog->resize(278, 174);
        label = new QLabel(ConfirmDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 60, 141, 41));
        buttonBox = new QDialogButtonBox(ConfirmDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(60, 130, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(ConfirmDialog);

        QMetaObject::connectSlotsByName(ConfirmDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDialog)
    {
        ConfirmDialog->setWindowTitle(QApplication::translate("ConfirmDialog", "ConfirmDialog", Q_NULLPTR));
        label->setText(QApplication::translate("ConfirmDialog", "\346\217\220\347\244\272\344\277\241\346\201\257\357\274\201\357\274\201\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDialog: public Ui_ConfirmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDIALOG_H
