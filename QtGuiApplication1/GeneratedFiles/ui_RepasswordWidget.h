/********************************************************************************
** Form generated from reading UI file 'RepasswordWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPASSWORDWIDGET_H
#define UI_REPASSWORDWIDGET_H

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

class Ui_RepasswordWidget
{
public:
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QWidget *RepasswordWidget)
    {
        if (RepasswordWidget->objectName().isEmpty())
            RepasswordWidget->setObjectName(QStringLiteral("RepasswordWidget"));
        RepasswordWidget->resize(400, 300);
        label_3 = new QLabel(RepasswordWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 180, 54, 12));
        label_2 = new QLabel(RepasswordWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 120, 54, 12));
        label = new QLabel(RepasswordWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 70, 54, 12));
        lineEdit_2 = new QLineEdit(RepasswordWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 110, 141, 31));
        lineEdit = new QLineEdit(RepasswordWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 60, 141, 31));
        lineEdit_3 = new QLineEdit(RepasswordWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 170, 141, 31));
        label_4 = new QLabel(RepasswordWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 20, 261, 20));
        pushButton = new QPushButton(RepasswordWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 240, 91, 23));

        retranslateUi(RepasswordWidget);

        QMetaObject::connectSlotsByName(RepasswordWidget);
    } // setupUi

    void retranslateUi(QWidget *RepasswordWidget)
    {
        RepasswordWidget->setWindowTitle(QApplication::translate("RepasswordWidget", "\345\257\206\347\240\201\346\211\276\345\233\236", Q_NULLPTR));
        label_3->setText(QApplication::translate("RepasswordWidget", "\350\272\253\344\273\275ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("RepasswordWidget", "\345\271\264\351\276\204", Q_NULLPTR));
        label->setText(QApplication::translate("RepasswordWidget", "\347\224\250\346\210\267\345\247\223\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("RepasswordWidget", "\350\257\267\345\212\241\345\277\205\345\241\253\345\206\231\345\256\214\345\205\250\345\207\206\347\241\256\347\232\204\344\277\241\346\201\257\344\273\245\344\276\277\346\211\276\345\233\236\345\257\206\347\240\201\357\274\201\357\274\201\357\274\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RepasswordWidget", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RepasswordWidget: public Ui_RepasswordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPASSWORDWIDGET_H
