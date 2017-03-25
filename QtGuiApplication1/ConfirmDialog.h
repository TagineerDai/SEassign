#pragma once

#include <QDialog>
#include "ui_ConfirmDialog.h"


//a MSG interface for different task
//OK Cancel btn
class ConfirmDialog : public QDialog
{
	Q_OBJECT

public:
	ConfirmDialog(QWidget *parent = Q_NULLPTR);
	~ConfirmDialog();

private:
	Ui::ConfirmDialog ui;
};
