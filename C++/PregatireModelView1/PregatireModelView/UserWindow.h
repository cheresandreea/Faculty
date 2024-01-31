#pragma once

#include <QMainWindow>
#include "ui_UserWindow.h"
#include "Service.h"
#include "IssueModel.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(IssueModel* i, Service& s, string username, bool isTester = false, QWidget* parent = nullptr);
	~UserWindow();

	void add();

	void remove();

	void resolveIssue();

private:
	Ui::UserWindowClass ui;
	Service& s;
	IssueModel* i;
	std::string username;
};
