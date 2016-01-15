#include "verticalbox.h"
#include <QVBoxLayout>
#include <QPushButton>

VerticalBox::VerticalBox(QWidget *parent) : QWidget(parent) {
	QVBoxLayout *vbox = new QVBoxLayout(this);
	vbox->setSpacing(1);

	QPushButton **buttons = new QPushButton*[5];


	for (int i = 0; i < 5; i++) {
		buttons[i] = new QPushButton(QString("BTN-%1").arg(i), this);

		vbox->addWidget(buttons[i]);
	}

	setLayout(vbox);
}
