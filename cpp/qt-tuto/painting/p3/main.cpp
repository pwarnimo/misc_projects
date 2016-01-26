#include <QDesktopWidget>
#include <QApplication>
#include "transparent_rectangles.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	TransparentRectangles window;

	window.resize(630, 90);
	window.setWindowTitle("Transparent rectangles");
	window.show();

	return app.exec();
}
