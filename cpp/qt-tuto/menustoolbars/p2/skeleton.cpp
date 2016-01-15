#include "skeleton.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>

Skeleton::Skeleton(QWidget *parent) : QMainWindow(parent) {
	QPixmap newpic("new.png");
	QPixmap openpic("open.png");
	QPixmap quitpic("quit.png");

	QAction *quit = new QAction("&Quit", this);

	QMenu *file;
	file = menuBar()->addMenu("&File");
	file->addAction(quit);

	connect(quit, &QAction::triggered, qApp, &QApplication::quit);

	QToolBar *toolbar = addToolBar("main toolbar");
	toolbar->addAction(QIcon(newpic), "New File");
	toolbar->addAction(QIcon(openpic), "Open File");
	toolbar->addSeparator();

	QAction *quit2 = toolbar->addAction(QIcon(quitpic), "Quit Application");
	connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

	QTextEdit *edit = new QTextEdit(this);

	setCentralWidget(edit);

	statusBar()->showMessage("Ready");
}
