#ifndef MINIPAINT_H
#define MINIPAINT_H

#include "ui_MiniPaint.h"

class MiniPaint : public QMainWindow, public Ui::MainWindow {
	Q_OBJECT

	public:
		MiniPaint(QMainWindow *parent = 0);
		~MiniPaint();

	private slots:
		void createNewDrawing();
};

#endif
