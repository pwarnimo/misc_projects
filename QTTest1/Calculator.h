#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "ui_Calculator.h"

class Calculator : public QMainWindow, public Ui::MainWindow  {
	Q_OBJECT

	public:
		Calculator(QMainWindow *parent = 0);
		~Calculator();
};

#endif
