/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QWidget *testerwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *testerhorizontalLayout;
    QPushButton *addpushButton;
    QLabel *label;
    QLineEdit *descriptionlineEdit;
    QPushButton *resolvepushButton;
    QLineEdit *removelineEdit;
    QPushButton *removepushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName("UserWindowClass");
        UserWindowClass->resize(654, 524);
        centralWidget = new QWidget(UserWindowClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");

        verticalLayout_2->addWidget(tableView);

        testerwidget = new QWidget(centralWidget);
        testerwidget->setObjectName("testerwidget");
        verticalLayout = new QVBoxLayout(testerwidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        testerhorizontalLayout = new QHBoxLayout();
        testerhorizontalLayout->setSpacing(6);
        testerhorizontalLayout->setObjectName("testerhorizontalLayout");
        addpushButton = new QPushButton(testerwidget);
        addpushButton->setObjectName("addpushButton");

        testerhorizontalLayout->addWidget(addpushButton);

        label = new QLabel(testerwidget);
        label->setObjectName("label");

        testerhorizontalLayout->addWidget(label);

        descriptionlineEdit = new QLineEdit(testerwidget);
        descriptionlineEdit->setObjectName("descriptionlineEdit");

        testerhorizontalLayout->addWidget(descriptionlineEdit);


        verticalLayout->addLayout(testerhorizontalLayout);


        verticalLayout_2->addWidget(testerwidget);

        resolvepushButton = new QPushButton(centralWidget);
        resolvepushButton->setObjectName("resolvepushButton");

        verticalLayout_2->addWidget(resolvepushButton);

        removelineEdit = new QLineEdit(centralWidget);
        removelineEdit->setObjectName("removelineEdit");

        verticalLayout_2->addWidget(removelineEdit);

        removepushButton = new QPushButton(centralWidget);
        removepushButton->setObjectName("removepushButton");

        verticalLayout_2->addWidget(removepushButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        UserWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 654, 22));
        UserWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UserWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        UserWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UserWindowClass);
        statusBar->setObjectName("statusBar");
        UserWindowClass->setStatusBar(statusBar);

        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QCoreApplication::translate("UserWindowClass", "UserWindow", nullptr));
        addpushButton->setText(QCoreApplication::translate("UserWindowClass", "Add", nullptr));
        label->setText(QCoreApplication::translate("UserWindowClass", "Description", nullptr));
        resolvepushButton->setText(QCoreApplication::translate("UserWindowClass", "Resolve", nullptr));
        removepushButton->setText(QCoreApplication::translate("UserWindowClass", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
