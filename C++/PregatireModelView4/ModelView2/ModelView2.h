#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ModelView2.h"
#include "Service.h"
#include "Model.h"

class ModelView2 : public QMainWindow
{
    Q_OBJECT

public:
    ModelView2(Model* model, std::string name, string ex, Service&s, QWidget *parent = nullptr);
    ~ModelView2();

    void add();

    void accept();

private:
    Ui::ModelView2Class ui;
    Service& service;
    Model* model;
    std::string name;
    std::string ex;
};
