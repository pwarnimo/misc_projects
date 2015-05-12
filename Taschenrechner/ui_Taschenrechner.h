/********************************************************************************
** Form generated from reading UI file 'Taschenrechner.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASCHENRECHNER_H
#define UI_TASCHENRECHNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
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
    QLabel *LabelA;
    QLabel *LabelB;
    QLabel *LabelC;
    QLineEdit *InputA;
    QLineEdit *InputB;
    QLineEdit *ResultC;
    QPushButton *Calculate;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(324, 308);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LabelA = new QLabel(centralwidget);
        LabelA->setObjectName(QString::fromUtf8("LabelA"));
        LabelA->setGeometry(QRect(20, 40, 57, 14));
        LabelB = new QLabel(centralwidget);
        LabelB->setObjectName(QString::fromUtf8("LabelB"));
        LabelB->setGeometry(QRect(20, 90, 57, 14));
        LabelC = new QLabel(centralwidget);
        LabelC->setObjectName(QString::fromUtf8("LabelC"));
        LabelC->setGeometry(QRect(20, 140, 57, 14));
        InputA = new QLineEdit(centralwidget);
        InputA->setObjectName(QString::fromUtf8("InputA"));
        InputA->setGeometry(QRect(110, 40, 113, 20));
        InputB = new QLineEdit(centralwidget);
        InputB->setObjectName(QString::fromUtf8("InputB"));
        InputB->setGeometry(QRect(110, 90, 113, 20));
        ResultC = new QLineEdit(centralwidget);
        ResultC->setObjectName(QString::fromUtf8("ResultC"));
        ResultC->setGeometry(QRect(110, 140, 113, 20));
        Calculate = new QPushButton(centralwidget);
        Calculate->setObjectName(QString::fromUtf8("Calculate"));
        Calculate->setGeometry(QRect(90, 210, 83, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 324, 19));
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
        LabelA->setText(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        LabelB->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        LabelC->setText(QApplication::translate("MainWindow", "A+B", 0, QApplication::UnicodeUTF8));
        Calculate->setText(QApplication::translate("MainWindow", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASCHENRECHNER_H
