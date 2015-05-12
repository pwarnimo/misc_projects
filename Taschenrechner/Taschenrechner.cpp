#include "Taschenrechner.h"

Taschenrechner::Taschenrechner(QMainWindow *parent) : QMainWindow(parent) {
	setupUi(this);
	InputA->setText("0");
	InputB->setText("0");

	connect(Calculate, SIGNAL(clicked()), this, SLOT(addAB()));
}
		   
Taschenrechner::~Taschenrechner() {
}

void Taschenrechner::addAB(){
	double a, b;
	a = (InputA -> text()).toDouble();
	b = (InputB -> text()).toDouble();
	ResultC -> setText(QString("%1").arg(a+b,0,'f',4));
}
