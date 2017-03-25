#pragma once

#include <QWidget>
#include "ui_LoginWindow.h"

class LoginWindow : public QWidget, public Ui::LoginWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = Q_NULLPTR);
	~LoginWindow();
};
