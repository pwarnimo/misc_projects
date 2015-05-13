#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <QtDebug>
#include <QMessageBox>

using namespace std;

Calculator::Calculator(QMainWindow *parent) : QMainWindow(parent) {
	setupUi(this);
	connect(btn1, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn2, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn3, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn4, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn5, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn6, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn7, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn8, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn9, SIGNAL(clicked()), this, SLOT(addToVal()));
	connect(btn0, SIGNAL(clicked()), this, SLOT(addToVal()));

	connect(btnPlus, SIGNAL(clicked()), this, SLOT(addition()));
	connect(btnMinus, SIGNAL(clicked()), this, SLOT(substract()));
	connect(btnMulti, SIGNAL(clicked()), this, SLOT(multiply()));

	connect(btnClear, SIGNAL(clicked()), this, SLOT(reset()));

	connect(btnCalculate, SIGNAL(clicked()), this, SLOT(calcResult()));

	this->statusBar()->setSizeGripEnabled(false);

	tmpValue = 0;
	result = 0;
	first = true;
}

Calculator::~Calculator() {
}

void Calculator::addToVal() {
	QPushButton *button = (QPushButton *)sender();
	QString strVal;

	if (tmpValue == 0) {
		strVal = "";
	}
	else {
		strVal = QString::number(tmpValue);
	}
	
	strVal.append(button->text());
	tmpValue = strVal.toInt();

	qDebug() << strVal.toStdString().c_str();

	edtDisplay->display(tmpValue);
}

void Calculator::addition() {
	result = result + tmpValue;
	edtDisplay->display(result);
	currentop = '+';
	tmpValue = 0;
}

void Calculator::substract() {
	if (first) {
		result = tmpValue;
		first = false;
	}
	else {
		result = result - tmpValue;
	}
	edtDisplay->display(result);
	currentop = '-';
	tmpValue = 0;
}

void Calculator::multiply() {
	if (first) {
		result = tmpValue;
		first = false;
	}
	else {
		result = result * tmpValue;
	}
	
	edtDisplay->display(result);
	currentop = '*';
	tmpValue = 0;
}

void Calculator::calcResult() {
	switch (currentop) {
		case '+': {
			qDebug() << "OP = +";
			result = result + tmpValue;
			edtDisplay->display(result);
		}
		break;
		
		case '-': {
			qDebug() << "OP = -";
			result = result - tmpValue;
			edtDisplay->display(result);
		}
		break;

		case '*': {
			qDebug() << "OP = *";
			result = result * tmpValue;
			edtDisplay->display(result);
		}
		break;
		
		case '/': {
			qDebug() << "OP = /";
			if (tmpValue == 0) {
				result = 0;
				
				QMessageBox msgbox;
				msgbox.setText("Cannot divide by zero!");
				msgbox.setIcon(QMessageBox::Critical);
				msgbox.setWindowTitle("Warning");
				msgbox.exec();
			}
			else {
				result = result / tmpValue;
			}
			
			edtDisplay->display(result);
		}
		break;
	}
}

void Calculator::reset() {
	result = 0;
	tmpValue = 0;
	first = true;

	edtDisplay->display(tmpValue);
}
