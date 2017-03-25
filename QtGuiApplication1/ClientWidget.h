#pragma once

#include <QWidget>
#include "ui_ClientWidget.h"

// control panel
// state panel

class ClientWidget : public QWidget, public Ui::ClientWidget
{
	Q_OBJECT

public:
	ClientWidget(QWidget *parent = Q_NULLPTR);
	~ClientWidget();
};
