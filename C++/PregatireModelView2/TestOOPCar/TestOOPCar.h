#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestOOPCar.h"
#include "Service.h"

class TestOOPCar : public QMainWindow
{
    Q_OBJECT

public:
    TestOOPCar(Service& s, QWidget *parent = nullptr);
    ~TestOOPCar();

    void populateList();
    void showCarsbyColor();
    void showCarsbyMan();
private:
    Ui::TestOOPCarClass ui;
    Service& service;
};
