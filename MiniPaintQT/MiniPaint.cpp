#include "MiniPaint.h"
#include <QMessageBox>
#include <QPainter>

MiniPaint::MiniPaint(QMainWindow *parent) : QMainWindow(parent) {
	setupUi(this);

	connect(actionNew, SIGNAL(triggered()), this, SLOT(createNewDrawing()));
}

MiniPaint::~MiniPaint() {
}

void MiniPaint::createNewDrawing() {
	QPainter painter(this);
}
