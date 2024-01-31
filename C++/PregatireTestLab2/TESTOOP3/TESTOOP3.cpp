#include "TESTOOP3.h"
#include "Service.h"
#include <QFont>

TESTOOP3::TESTOOP3(Service& s,QWidget *parent)
    : QMainWindow(parent), serv{s}
{
    ui.setupUi(this);
	s.readFile();
	this->populate();

	connect(ui.showTaskspushButton, &QPushButton::clicked, this, &TESTOOP3::showTasksDuration);

}

TESTOOP3::~TESTOOP3()
{}

void TESTOOP3::populate()
{
    ui.listWidget->clear();
	vector<Task> tasks = serv.getTasks();


	sort(tasks.begin(), tasks.end(), [](Task t1, Task t2)
		{
			if (t1.getPriority() == t2.getPriority()) {
				return t1.getDuration() < t2.getDuration();
			}
			return t1.getPriority() < t2.getPriority();

		});


	for (auto &t : tasks)
	{

		/*QListWidgetItem* item = new QListWidgetItem();
		QString itemText = QString::fromStdString(t.getDescription() + " " + std::to_string(t.getDuration()) + " " + std::to_string(t.getPriority()));
	

		QFont font = item->font();

		if (t.getPriority() == 1)
		{
			font.setBold(true);
			ui.itemText->setFont(font);
		}
		else {
			font.setBold(false);
			ui.listWidget->setFont(font);
		}
	*/
		ui.listWidget->addItem(QString::fromStdString(t.getDescription() + " " + to_string(t.getDuration()) + " " + to_string(t.getPriority())));
	}

}

void TESTOOP3::showTasksDuration()
{

	ui.listWidget_2->clear();
	QString text = ui.showlineEdit->text();

	vector<Task> tasks = serv.getTasks();
	int dur = 0;

	for (Task t : tasks)
	{
		if (t.getPriority() == stoi(text.toStdString()))
		{
			ui.listWidget_2->addItem(QString::fromStdString(t.getDescription() + " " + to_string(t.getDuration()) + " " + to_string(t.getPriority())));
			dur += t.getDuration();
		}
	}
	if (dur != 0)

	{
		ui.listWidget_2->addItem(QString::fromStdString(to_string(dur)));

	}
	else 

		ui.listWidget_2->addItem(QString::fromStdString("Error!"));
}
