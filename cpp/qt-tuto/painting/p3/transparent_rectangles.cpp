#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include "transparent_rectangles.h"

TransparentRectangles::TransparentRectangles(QWidget *parent) : QWidget(parent) {}

void TransparentRectangles::paintEvent(QPaintEvent *e) {
	Q_UNUSED(e);

	doPainting();
}

void TransparentRectangles::doPainting() {
	QPainter painter(this);

	for (int i = 0; i <= 11; i++) {
		painter.setOpacity(i * .1);
		painter.fillRect(50 * i, 20, 40, 40, Qt::darkGray);
	}
}
