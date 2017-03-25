#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

//control panel
//client state panel
//power btn

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
};
