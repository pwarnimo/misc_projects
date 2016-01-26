#pragma once

#include <QWidget>

class Donut : public QWidget {
	public:
		Donut(QWidget *parent = 0);

	protected:
		void paintEvent(QPaintEvent *e);

	private:
		void doPainting();
};
