/********************************************************************************
** Form generated from reading UI file 'MiniPaint.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIPAINT_H
#define UI_MINIPAINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionExit;
    QAction *actionNewPainting;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionLine;
    QAction *actionElipse;
    QAction *actionRectangle;
    QAction *action_3;
    QAction *actionForeground_color;
    QAction *actionBackground_color;
    QWidget *centralwidget;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(643, 485);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNewPainting = new QAction(MainWindow);
        actionNewPainting->setObjectName(QString::fromUtf8("actionNewPainting"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionElipse = new QAction(MainWindow);
        actionElipse->setObjectName(QString::fromUtf8("actionElipse"));
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        actionForeground_color = new QAction(MainWindow);
        actionForeground_color->setObjectName(QString::fromUtf8("actionForeground_color"));
        actionBackground_color = new QAction(MainWindow);
        actionBackground_color->setObjectName(QString::fromUtf8("actionBackground_color"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        toolBar->addAction(actionNewPainting);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionLine);
        menuEdit->addAction(actionElipse);
        menuEdit->addAction(actionRectangle);
        menuEdit->addSeparator();
        menuEdit->addAction(actionForeground_color);
        menuEdit->addAction(actionBackground_color);

        retranslateUi(MainWindow);
        QObject::connect(actionNewPainting, SIGNAL(triggered()), actionNew, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MiniPaintQT", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionNewPainting->setText(QApplication::translate("MainWindow", "NEW", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionLine->setText(QApplication::translate("MainWindow", "Line", 0, QApplication::UnicodeUTF8));
        actionElipse->setText(QApplication::translate("MainWindow", "Elipse", 0, QApplication::UnicodeUTF8));
        actionRectangle->setText(QApplication::translate("MainWindow", "Rectangle", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        actionForeground_color->setText(QApplication::translate("MainWindow", "Foreground color", 0, QApplication::UnicodeUTF8));
        actionBackground_color->setText(QApplication::translate("MainWindow", "Background color", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIPAINT_H
