/********************************************************************************
** Form generated from reading UI file 'TestOOPCar.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOOPCAR_H
#define UI_TESTOOPCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestOOPCarClass
{
public:
    QWidget *centralWidget;
    QListWidget *carlistWidget;
    QLineEdit *inputlineEdit;
    QPushButton *showCarspushButton;
    QListWidget *carstSpecificManlistWidget;
    QLabel *numberlabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestOOPCarClass)
    {
        if (TestOOPCarClass->objectName().isEmpty())
            TestOOPCarClass->setObjectName("TestOOPCarClass");
        TestOOPCarClass->resize(812, 468);
        centralWidget = new QWidget(TestOOPCarClass);
        centralWidget->setObjectName("centralWidget");
        carlistWidget = new QListWidget(centralWidget);
        carlistWidget->setObjectName("carlistWidget");
        carlistWidget->setGeometry(QRect(20, 10, 256, 192));
        inputlineEdit = new QLineEdit(centralWidget);
        inputlineEdit->setObjectName("inputlineEdit");
        inputlineEdit->setGeometry(QRect(560, 20, 113, 22));
        showCarspushButton = new QPushButton(centralWidget);
        showCarspushButton->setObjectName("showCarspushButton");
        showCarspushButton->setGeometry(QRect(560, 50, 75, 24));
        carstSpecificManlistWidget = new QListWidget(centralWidget);
        carstSpecificManlistWidget->setObjectName("carstSpecificManlistWidget");
        carstSpecificManlistWidget->setGeometry(QRect(370, 50, 171, 61));
        numberlabel = new QLabel(centralWidget);
        numberlabel->setObjectName("numberlabel");
        numberlabel->setGeometry(QRect(370, 20, 49, 16));
        TestOOPCarClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestOOPCarClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 812, 22));
        TestOOPCarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestOOPCarClass);
        mainToolBar->setObjectName("mainToolBar");
        TestOOPCarClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestOOPCarClass);
        statusBar->setObjectName("statusBar");
        TestOOPCarClass->setStatusBar(statusBar);

        retranslateUi(TestOOPCarClass);

        QMetaObject::connectSlotsByName(TestOOPCarClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestOOPCarClass)
    {
        TestOOPCarClass->setWindowTitle(QCoreApplication::translate("TestOOPCarClass", "TestOOPCar", nullptr));
        showCarspushButton->setText(QCoreApplication::translate("TestOOPCarClass", "PushButton", nullptr));
        numberlabel->setText(QCoreApplication::translate("TestOOPCarClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestOOPCarClass: public Ui_TestOOPCarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOOPCAR_H
