#pragma once

#include <QDialog>
#include "ui_LogoutDialog.h"

// confirm cancel btn

class LogoutDialog : public QDialog
{
	Q_OBJECT

public:
	LogoutDialog(QWidget *parent = Q_NULLPTR);
	~LogoutDialog();
private:
	Ui::LogoutDialog ui;
};
