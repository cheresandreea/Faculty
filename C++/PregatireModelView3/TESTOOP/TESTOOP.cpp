#include "TESTOOP.h"
#include "Service.h"

TESTOOP::TESTOOP(Service& s,QWidget *parent)
    : QMainWindow(parent), service{ s }
{
    ui.setupUi(this);
    populate();
    connect(ui.sortpushButton, &QPushButton::clicked, this, &TESTOOP::sortBills);
    connect(ui.calculateTotalpushButton, &QPushButton::clicked, this, &TESTOOP::calculateTotal);
}

TESTOOP::~TESTOOP()
{}

void TESTOOP::populate()
{
    ui.billlistWidget->clear();
    for (auto b : service.getAll())
    {
		ui.billlistWidget->addItem(QString::fromStdString(b.getName() + to_string(b.getSum())));
	}
}

void TESTOOP::sortBills()
{
    ui.billlistWidget->clear();
    vector<Bill>bills = service.getAll();
    sort(bills.begin(), bills.end(), [](Bill b1, Bill b2) {return b1.getName() < b2.getName(); });
    for (auto b : bills )
    {
        ui.billlistWidget->addItem(QString::fromStdString(b.getName() + to_string(b.getSum())));
    }
}

void TESTOOP::calculateTotal()
{
    string company = ui.companylineEdit->text().toStdString();
    int total = 0;
    this->ui.totalsumlabel->clear();

    for (auto b : service.getAll())
    {
		if (b.getName() == company && b.getIsPaid() == false)
			total += b.getSum();
	}
    ui.totalsumlabel->setText(QString::fromStdString(to_string(total)));
}