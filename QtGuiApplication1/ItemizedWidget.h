#pragma once

#include <QWidget>
#include "ui_ItemizedWidget.h"

// query panel
// message list
// exit btn

class ItemizedWidget : public QWidget, public Ui::ItemizedWidget
{
	Q_OBJECT

public:
	ItemizedWidget(QWidget *parent = Q_NULLPTR);
	~ItemizedWidget();
};
