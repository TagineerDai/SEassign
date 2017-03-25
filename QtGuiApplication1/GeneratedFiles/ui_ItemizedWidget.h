/********************************************************************************
** Form generated from reading UI file 'ItemizedWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMIZEDWIDGET_H
#define UI_ITEMIZEDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemizedWidget
{
public:

    void setupUi(QWidget *ItemizedWidget)
    {
        if (ItemizedWidget->objectName().isEmpty())
            ItemizedWidget->setObjectName(QStringLiteral("ItemizedWidget"));
        ItemizedWidget->resize(400, 300);

        retranslateUi(ItemizedWidget);

        QMetaObject::connectSlotsByName(ItemizedWidget);
    } // setupUi

    void retranslateUi(QWidget *ItemizedWidget)
    {
        ItemizedWidget->setWindowTitle(QApplication::translate("ItemizedWidget", "ItemizedWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ItemizedWidget: public Ui_ItemizedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMIZEDWIDGET_H
