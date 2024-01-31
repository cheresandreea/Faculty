#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TESTOOP3.h"
#include "Service.h"

class TESTOOP3 : public QMainWindow
{
    Q_OBJECT

public:
    TESTOOP3(Service& s, QWidget *parent = nullptr);
    ~TESTOOP3();

    void populate();
    void showTasksDuration();

private:
    Ui::TESTOOP3Class ui;
    Service& serv;
};
