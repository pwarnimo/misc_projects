#pragma once

#include <QWidget>

class TransparentRectangles : public QWidget {
	public:
		TransparentRectangles(QWidget *parent = 0);

	protected:
		void paintEvent(QPaintEvent *event);
		void doPainting();
};
