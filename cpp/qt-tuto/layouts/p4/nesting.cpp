#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include "nesting.h"

Layouts::Layouts(QWidget *parent) : QWidget(parent) {
	QVBoxLayout *vbox = new QVBoxLayout();
	QHBoxLayout *hbox = new QHBoxLayout(this);

	QListWidget *lw = new QListWidget(this);
	lw->addItem("Endless");
	lw->addItem("Descent");
	lw->addItem("Into Ruin");
	lw->addItem("Hail");
	lw->addItem("Satan");
	lw->addItem("Worship");
	lw->addItem("Doom");

	QPushButton *add = new QPushButton("Add", this);
	QPushButton *rename = new QPushButton("Rename", this);
	QPushButton *remove = new QPushButton("Remove", this);
	QPushButton *removeall = new QPushButton("Remove all", this);

	vbox->setSpacing(3);
	vbox->addStretch(1);
	vbox->addWidget(add);
	vbox->addWidget(rename);
	vbox->addWidget(remove);
	vbox->addWidget(removeall);
	vbox->addStretch(1);

	hbox->addWidget(lw);
	hbox->addSpacing(15);
	hbox->addLayout(vbox);

	setLayout(hbox);
}
