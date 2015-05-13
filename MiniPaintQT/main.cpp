#include "MiniPaint.h"
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	MiniPaint w;
	w.show();
	return a.exec();
}
