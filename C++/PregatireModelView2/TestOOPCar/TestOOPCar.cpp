#include "TestOOPCar.h"
#include "Service.h"
#include <qcolor.h>
#include <qfont.h>



TestOOPCar::TestOOPCar(Service& s, QWidget* parent)
    : QMainWindow(parent), service(s)
{
    ui.setupUi(this);
    this->populateList();
    this->showCarsbyColor();

    QObject::connect(ui.showCarspushButton, &QPushButton::clicked, this, &TestOOPCar::showCarsbyMan);
}

TestOOPCar::~TestOOPCar()
{}

void TestOOPCar::populateList()
{
    this->ui.carlistWidget->clear();
    vector<Car> cars = this->service.getAll();
    
    sort(cars.begin(), cars.end(), [](Car car1, Car car2) { return car1.getName() < car2.getName(); });

    for (auto c : cars)
    {
        this->ui.carlistWidget->addItem(QString::fromStdString(c.getName() + c.getModel()));
    }
}

//Show the cars in the list such that the font colour of each one is the same as the car’s colour(assume we only have colours the same as Qt predefined colours –class QColor). 

void TestOOPCar::showCarsbyColor()
{
    ui.carlistWidget->clear();
    vector<Car> cars = service.getAll();
    //Show the cars in the list such that the font colour of each one is the same as the car’s colour(assume we only have colours the same as Qt predefined colours –class QColor). 

    for (Car c : cars)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(c.getName() + " - " + c.getModel()));
        QColor color(c.getColor().c_str());
        item->setForeground(color);
        this->ui.carlistWidget->addItem(item);
    }
}

void TestOOPCar::showCarsbyMan()
{
    string car = ui.inputlineEdit->text().toStdString();
    ui.carstSpecificManlistWidget->clear();
    vector<Car> cars = service.getAll();
    int cont = 0;
    for (Car c : cars)
    {
        if (c.getName() == car)
        {
            ui.carstSpecificManlistWidget->addItem(QString::fromStdString(c.getName() + " - " + c.getModel() + to_string(c.getYear()) + c.getColor()));
            cont++;
        }
    }
    ui.numberlabel->setText(QString::fromStdString(to_string(cont)));
}