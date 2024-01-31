/********************************************************************************
** Form generated from reading UI file 'PregatireModelView.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREGATIREMODELVIEW_H
#define UI_PREGATIREMODELVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PregatireModelViewClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PregatireModelViewClass)
    {
        if (PregatireModelViewClass->objectName().isEmpty())
            PregatireModelViewClass->setObjectName("PregatireModelViewClass");
        PregatireModelViewClass->resize(600, 400);
        menuBar = new QMenuBar(PregatireModelViewClass);
        menuBar->setObjectName("menuBar");
        PregatireModelViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PregatireModelViewClass);
        mainToolBar->setObjectName("mainToolBar");
        PregatireModelViewClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PregatireModelViewClass);
        centralWidget->setObjectName("centralWidget");
        PregatireModelViewClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PregatireModelViewClass);
        statusBar->setObjectName("statusBar");
        PregatireModelViewClass->setStatusBar(statusBar);

        retranslateUi(PregatireModelViewClass);

        QMetaObject::connectSlotsByName(PregatireModelViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *PregatireModelViewClass)
    {
        PregatireModelViewClass->setWindowTitle(QCoreApplication::translate("PregatireModelViewClass", "PregatireModelView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PregatireModelViewClass: public Ui_PregatireModelViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREGATIREMODELVIEW_H
