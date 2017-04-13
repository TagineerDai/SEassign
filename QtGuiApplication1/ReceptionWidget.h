#pragma once

#include <QWidget>
#include "ui_ReceptionWidget.h"

class ReceptionWidget : public QWidget
{
	Q_OBJECT

public:
	ReceptionWidget(QWidget *parent = Q_NULLPTR);
	~ReceptionWidget();

private:
	Ui::ReceptionWidget ui;
};
