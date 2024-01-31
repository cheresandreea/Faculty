/********************************************************************************
** Form generated from reading UI file 'ModelView2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELVIEW2_H
#define UI_MODELVIEW2_H

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

class Ui_ModelView2Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QLabel *label_2;
    QLineEdit *actlineEdit;
    QPushButton *addpushButton;
    QLabel *label;
    QLineEdit *descriptionlineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *acceptpushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModelView2Class)
    {
        if (ModelView2Class->objectName().isEmpty())
            ModelView2Class->setObjectName("ModelView2Class");
        ModelView2Class->resize(605, 505);
        centralWidget = new QWidget(ModelView2Class);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        actlineEdit = new QLineEdit(centralWidget);
        actlineEdit->setObjectName("actlineEdit");

        verticalLayout->addWidget(actlineEdit);

        addpushButton = new QPushButton(centralWidget);
        addpushButton->setObjectName("addpushButton");

        verticalLayout->addWidget(addpushButton);

        label = new QLabel(centralWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        descriptionlineEdit = new QLineEdit(centralWidget);
        descriptionlineEdit->setObjectName("descriptionlineEdit");

        verticalLayout->addWidget(descriptionlineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        acceptpushButton = new QPushButton(widget);
        acceptpushButton->setObjectName("acceptpushButton");

        horizontalLayout->addWidget(acceptpushButton);


        verticalLayout_2->addWidget(widget);

        ModelView2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ModelView2Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 605, 22));
        ModelView2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModelView2Class);
        mainToolBar->setObjectName("mainToolBar");
        ModelView2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ModelView2Class);
        statusBar->setObjectName("statusBar");
        ModelView2Class->setStatusBar(statusBar);

        retranslateUi(ModelView2Class);

        QMetaObject::connectSlotsByName(ModelView2Class);
    } // setupUi

    void retranslateUi(QMainWindow *ModelView2Class)
    {
        ModelView2Class->setWindowTitle(QCoreApplication::translate("ModelView2Class", "ModelView2", nullptr));
        label_2->setText(QCoreApplication::translate("ModelView2Class", "Add act:", nullptr));
        addpushButton->setText(QCoreApplication::translate("ModelView2Class", "Add", nullptr));
        label->setText(QCoreApplication::translate("ModelView2Class", "Add description:", nullptr));
        acceptpushButton->setText(QCoreApplication::translate("ModelView2Class", "Accept idea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelView2Class: public Ui_ModelView2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELVIEW2_H
