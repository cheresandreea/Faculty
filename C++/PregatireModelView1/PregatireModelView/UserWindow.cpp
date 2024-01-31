#include "UserWindow.h"
#include <qobject.h>
#include <qmessagebox.h>

UserWindow::UserWindow(IssueModel* i, Service& s, string username, bool isTester, QWidget* parent)
	: QMainWindow(parent), s{ s }, i{ i }, username{ username }
{
	ui.setupUi(this);
	ui.tableView->setModel(this->i);

	if (!isTester)
	{
		ui.testerwidget->hide();
	}
	else {
		ui.resolvepushButton->hide();
	}

	QObject::connect(ui.addpushButton, &QPushButton::clicked, this, &UserWindow::add);
	QObject::connect(ui.removepushButton, &QPushButton::clicked, this, &UserWindow::remove);
	QObject::connect(ui.resolvepushButton, &QPushButton::clicked, this, &UserWindow::resolveIssue);
	
}

UserWindow::~UserWindow()
{}

void UserWindow::add()
{
	string text = ui.descriptionlineEdit->text().toStdString();
	Issue i1{ text, "open", this->username, "" };
	if (s.getIssueByDescription(i1.getDescription()) == true)
	{
		QMessageBox* m = new QMessageBox();
		m->show();
		return;
	}
	i->add(i1);
}

void UserWindow::remove()
{
	string text = ui.removelineEdit->text().toStdString();
	int pos = s.getIssueByDes(text);
	if (pos == -1)
	{
		QMessageBox* m = new QMessageBox();
		m->show();
		return;
	}
	i->remove(pos);

}

void UserWindow::resolveIssue()
{
	QModelIndexList selectedIndexes = ui.tableView->selectionModel()->selectedIndexes();
	if (!selectedIndexes.empty())
	{
		int selectedRow = selectedIndexes.first().row();
		Issue& selectedIssue = s.getIssues()[selectedRow];
		
		string solver = ui.tableView->windowTitle().toStdString();
		selectedIssue.setSolver(solver);
		selectedIssue.setStatus("closed");

	}
}