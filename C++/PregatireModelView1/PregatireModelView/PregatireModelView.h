#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PregatireModelView.h"

class PregatireModelView : public QMainWindow
{
    Q_OBJECT

public:
    PregatireModelView(QWidget *parent = nullptr);
    ~PregatireModelView();

private:
    Ui::PregatireModelViewClass ui;
};
