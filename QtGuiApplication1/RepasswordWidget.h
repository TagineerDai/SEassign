#pragma once

#include <QWidget>
#include "ui_RepasswordWidget.h"

class RepasswordWidget : public QWidget
{
	Q_OBJECT

public:
	RepasswordWidget(QWidget *parent = Q_NULLPTR);
	~RepasswordWidget();

private:
	Ui::RepasswordWidget ui;
};
