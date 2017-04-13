/********************************************************************************
** Form generated from reading UI file 'ReceptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEPTIONWIDGET_H
#define UI_RECEPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceptionWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *comboBox;
    QRadioButton *radioButton;
    QWidget *tab_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QTableView *tableView;
    QLabel *label_4;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *ReceptionWidget)
    {
        if (ReceptionWidget->objectName().isEmpty())
            ReceptionWidget->setObjectName(QStringLiteral("ReceptionWidget"));
        ReceptionWidget->resize(613, 608);
        tabWidget = new QTabWidget(ReceptionWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 581, 171));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 30, 241, 41));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(240, 90, 111, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 54, 21));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 40, 113, 20));
        dateEdit = new QDateEdit(tab_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(160, 90, 130, 22));
        dateEdit_2 = new QDateEdit(tab_2);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(340, 90, 130, 22));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 90, 54, 12));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 90, 54, 21));
        tabWidget->addTab(tab_2, QString());
        pushButton = new QPushButton(ReceptionWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(444, 200, 131, 41));
        tableView = new QTableView(ReceptionWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 280, 611, 331));
        label_4 = new QLabel(ReceptionWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 250, 131, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        verticalScrollBar = new QScrollBar(ReceptionWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(590, 280, 20, 331));
        verticalScrollBar->setOrientation(Qt::Vertical);

        retranslateUi(ReceptionWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReceptionWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceptionWidget)
    {
        ReceptionWidget->setWindowTitle(QApplication::translate("ReceptionWidget", "\345\211\215\345\217\260\346\250\241\345\274\217", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ReceptionWidget", "\347\224\237\346\210\220\346\227\245\346\212\245\350\241\250", Q_NULLPTR)
         << QApplication::translate("ReceptionWidget", "\347\224\237\346\210\220\345\221\250\346\212\245\350\241\250", Q_NULLPTR)
         << QApplication::translate("ReceptionWidget", "\347\224\237\346\210\220\345\271\264\346\212\245\350\241\250", Q_NULLPTR)
        );
        comboBox->setCurrentText(QApplication::translate("ReceptionWidget", "\347\224\237\346\210\220\346\227\245\346\212\245\350\241\250", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ReceptionWidget", "\346\230\257\345\220\246\345\220\214\346\227\266\346\211\223\345\215\260\357\274\237", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ReceptionWidget", "\346\212\245\350\241\250\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("ReceptionWidget", "\346\210\277\351\227\264\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReceptionWidget", "\350\207\263", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReceptionWidget", "\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ReceptionWidget", "\350\264\246\345\215\225\346\237\245\350\257\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ReceptionWidget", "\346\237\245\350\257\242", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReceptionWidget", "\343\200\220\346\237\245\350\257\242\347\273\223\346\236\234\343\200\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceptionWidget: public Ui_ReceptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEPTIONWIDGET_H
