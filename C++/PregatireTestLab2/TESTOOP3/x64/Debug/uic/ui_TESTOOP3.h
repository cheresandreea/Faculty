/********************************************************************************
** Form generated from reading UI file 'TESTOOP3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOOP3_H
#define UI_TESTOOP3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TESTOOP3Class
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QLineEdit *showlineEdit;
    QPushButton *showTaskspushButton;
    QListWidget *listWidget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TESTOOP3Class)
    {
        if (TESTOOP3Class->objectName().isEmpty())
            TESTOOP3Class->setObjectName("TESTOOP3Class");
        TESTOOP3Class->resize(533, 400);
        centralWidget = new QWidget(TESTOOP3Class);
        centralWidget->setObjectName("centralWidget");
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 10, 256, 192));
        showlineEdit = new QLineEdit(centralWidget);
        showlineEdit->setObjectName("showlineEdit");
        showlineEdit->setGeometry(QRect(290, 20, 113, 21));
        showTaskspushButton = new QPushButton(centralWidget);
        showTaskspushButton->setObjectName("showTaskspushButton");
        showTaskspushButton->setGeometry(QRect(290, 50, 161, 24));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(290, 90, 221, 61));
        TESTOOP3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TESTOOP3Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 533, 22));
        TESTOOP3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TESTOOP3Class);
        mainToolBar->setObjectName("mainToolBar");
        TESTOOP3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TESTOOP3Class);
        statusBar->setObjectName("statusBar");
        TESTOOP3Class->setStatusBar(statusBar);

        retranslateUi(TESTOOP3Class);

        QMetaObject::connectSlotsByName(TESTOOP3Class);
    } // setupUi

    void retranslateUi(QMainWindow *TESTOOP3Class)
    {
        TESTOOP3Class->setWindowTitle(QCoreApplication::translate("TESTOOP3Class", "TESTOOP3", nullptr));
        showTaskspushButton->setText(QCoreApplication::translate("TESTOOP3Class", "Show tasks and duration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TESTOOP3Class: public Ui_TESTOOP3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOOP3_H
