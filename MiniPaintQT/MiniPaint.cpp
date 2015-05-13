#include "MiniPaint.h"
#include <QMessageBox>

MiniPaint::MiniPaint(QMainWindow *parent) : QMainWindow(parent) {
	setupUi(this);

	connect(actionNew, SIGNAL(triggered()), this, SLOT(createNewDrawing()));
}

MiniPaint::~MiniPaint() {
}

void MiniPaint::createNewDrawing() {
	QMessageBox msgBox;
	msgBox.setText("This is a test");
	msgBox.exec();
}
