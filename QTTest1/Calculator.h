#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "ui_Calculator.h"
#include <string>

class Calculator : public QMainWindow, public Ui::MainWindow  {
	Q_OBJECT

	public:
		Calculator(QMainWindow *parent = 0);
		~Calculator();
	
	private slots:
		void calculate();
		void addToVal();

	private:
		std::string val;
};

#endif
