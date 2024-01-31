#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TESTOOP.h"
#include "Service.h"

class TESTOOP : public QMainWindow
{
    Q_OBJECT

public:
    TESTOOP(Service& s, QWidget *parent = nullptr);
    ~TESTOOP();

    void populate();

    void sortBills();

    void calculateTotal();

private:
    Ui::TESTOOPClass ui;
    Service& service;
};
