#pragma once

#include <QWidget>
#include "ui_ServerWidget.h"

class ServerWidget : public QWidget
{
	Q_OBJECT

public:
	ServerWidget(QWidget *parent = Q_NULLPTR);
	~ServerWidget();

private:
	Ui::ServerWidget ui;
};
