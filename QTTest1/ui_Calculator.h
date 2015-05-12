/********************************************************************************
** Form generated from reading UI file 'Calculator.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn1;
    QLCDNumber *edtDisplay;
    QPushButton *btn4;
    QPushButton *btn7;
    QPushButton *btn2;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btn3;
    QPushButton *btn6;
    QPushButton *btn9;
    QPushButton *btn0;
    QPushButton *btnCalculate;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QPushButton *btnMulti;
    QPushButton *btnDiv;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(222, 274);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(10, 40, 41, 41));
        edtDisplay = new QLCDNumber(centralwidget);
        edtDisplay->setObjectName(QString::fromUtf8("edtDisplay"));
        edtDisplay->setGeometry(QRect(10, 10, 201, 23));
        edtDisplay->setFrameShape(QFrame::Box);
        edtDisplay->setNumDigits(18);
        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(10, 90, 41, 41));
        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setGeometry(QRect(10, 140, 41, 41));
        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(60, 40, 41, 41));
        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setGeometry(QRect(60, 90, 41, 41));
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setGeometry(QRect(60, 140, 41, 41));
        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setGeometry(QRect(110, 40, 41, 41));
        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setGeometry(QRect(110, 90, 41, 41));
        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setGeometry(QRect(110, 140, 41, 41));
        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setGeometry(QRect(10, 190, 41, 41));
        btnCalculate = new QPushButton(centralwidget);
        btnCalculate->setObjectName(QString::fromUtf8("btnCalculate"));
        btnCalculate->setGeometry(QRect(60, 190, 91, 41));
        btnPlus = new QPushButton(centralwidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        btnPlus->setGeometry(QRect(170, 40, 41, 41));
        btnMinus = new QPushButton(centralwidget);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));
        btnMinus->setGeometry(QRect(170, 90, 41, 41));
        btnMulti = new QPushButton(centralwidget);
        btnMulti->setObjectName(QString::fromUtf8("btnMulti"));
        btnMulti->setGeometry(QRect(170, 140, 41, 41));
        btnDiv = new QPushButton(centralwidget);
        btnDiv->setObjectName(QString::fromUtf8("btnDiv"));
        btnDiv->setGeometry(QRect(170, 190, 41, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 222, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btnCalculate->setText(QApplication::translate("MainWindow", "Calc", 0, QApplication::UnicodeUTF8));
        btnPlus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        btnMinus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        btnMulti->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        btnDiv->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
