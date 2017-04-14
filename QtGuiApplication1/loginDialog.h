#pragma once
#include "ConfigAC.h"
#include <QDialog>
#include "ui_loginDialog.h"

extern ROLE role;

class loginDialog : public QDialog
{
	Q_OBJECT

public:
	loginDialog(QWidget *parent = Q_NULLPTR);
	~loginDialog();
private slots:
	void on_Bhelp_clicked();
	void on_Blogin_clicked();
	void on_Bcancel_clicked();
	void on_closeButton_clicked();
private:
	Ui::loginDialog ui;
};
