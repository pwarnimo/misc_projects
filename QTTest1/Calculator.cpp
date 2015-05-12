#include "Calculator.h"
#include <iostream>
#include <sstream>

using namespace std;

Calculator::Calculator(QMainWindow *parent) : QMainWindow(parent) {
	setupUi(this);
	connect(btnCalculate, SIGNAL(clicked()), this, SLOT(calculate()));
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
}

Calculator::~Calculator() {
}

void Calculator::calculate() {
	cout << "test111\n";
}

void Calculator::addToVal() {
	QPushButton *button = (QPushButton *)sender();

	stringstream ss;

	ss << val << button->text()[0].digitValue();
	val = ss.str();

	cout << "CurrVal=" << val << "\n";

	edtDisplay->display(atoi(val.c_str()));
}
