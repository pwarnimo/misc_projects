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
		void addToVal();
		void addition();
		void substract();
		void multiply();
		void calcResult();
		void reset();

	private:
		int tmpValue;
		int result;
		char currentop;
		bool first;
};

#endif
