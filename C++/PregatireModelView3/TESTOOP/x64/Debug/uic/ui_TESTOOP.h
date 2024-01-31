/********************************************************************************
** Form generated from reading UI file 'TESTOOP.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOOP_H
#define UI_TESTOOP_H

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

class Ui_TESTOOPClass
{
public:
    QWidget *centralWidget;
    QListWidget *billlistWidget;
    QPushButton *sortpushButton;
    QLineEdit *companylineEdit;
    QPushButton *calculateTotalpushButton;
    QLabel *totalsumlabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TESTOOPClass)
    {
        if (TESTOOPClass->objectName().isEmpty())
            TESTOOPClass->setObjectName("TESTOOPClass");
        TESTOOPClass->resize(693, 449);
        centralWidget = new QWidget(TESTOOPClass);
        centralWidget->setObjectName("centralWidget");
        billlistWidget = new QListWidget(centralWidget);
        billlistWidget->setObjectName("billlistWidget");
        billlistWidget->setGeometry(QRect(50, 20, 256, 192));
        sortpushButton = new QPushButton(centralWidget);
        sortpushButton->setObjectName("sortpushButton");
        sortpushButton->setGeometry(QRect(380, 30, 75, 24));
        companylineEdit = new QLineEdit(centralWidget);
        companylineEdit->setObjectName("companylineEdit");
        companylineEdit->setGeometry(QRect(390, 120, 113, 22));
        calculateTotalpushButton = new QPushButton(centralWidget);
        calculateTotalpushButton->setObjectName("calculateTotalpushButton");
        calculateTotalpushButton->setGeometry(QRect(530, 120, 111, 24));
        totalsumlabel = new QLabel(centralWidget);
        totalsumlabel->setObjectName("totalsumlabel");
        totalsumlabel->setGeometry(QRect(390, 160, 49, 16));
        TESTOOPClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TESTOOPClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 693, 22));
        TESTOOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TESTOOPClass);
        mainToolBar->setObjectName("mainToolBar");
        TESTOOPClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TESTOOPClass);
        statusBar->setObjectName("statusBar");
        TESTOOPClass->setStatusBar(statusBar);

        retranslateUi(TESTOOPClass);

        QMetaObject::connectSlotsByName(TESTOOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *TESTOOPClass)
    {
        TESTOOPClass->setWindowTitle(QCoreApplication::translate("TESTOOPClass", "TESTOOP", nullptr));
        sortpushButton->setText(QCoreApplication::translate("TESTOOPClass", "Sort", nullptr));
        calculateTotalpushButton->setText(QCoreApplication::translate("TESTOOPClass", "Calculate total", nullptr));
        totalsumlabel->setText(QCoreApplication::translate("TESTOOPClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TESTOOPClass: public Ui_TESTOOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOOP_H
