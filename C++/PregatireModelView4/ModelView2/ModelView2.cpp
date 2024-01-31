#include "ModelView2.h"
#include <QMessageBox>


ModelView2::ModelView2(Model* model,std::string name, string ex, Service& s,QWidget *parent)
    : QMainWindow(parent), service(s), name{ name }, model{ model }, ex{ ex }
{
    ui.setupUi(this);
    ui.tableView->setModel(model);
    if(ex != "Senior")
        ui.acceptpushButton->hide();

    QObject::connect(ui.addpushButton, &QPushButton::clicked, this, &ModelView2::add);
    QObject::connect(ui.acceptpushButton, &QPushButton::clicked, this, &ModelView2::accept);
}

ModelView2::~ModelView2()
{}

void ModelView2::add()
{
    string description = ui.descriptionlineEdit->text().toStdString();
    string act = ui.actlineEdit->text().toStdString();
    string n = name;
    Idea i = Idea(description, "proposed", n, stoi(act));
    if (description.empty() || (act != "1" && act != "2" && act != "3") || service.verifDescription(description) == false)
    {
        QMessageBox::critical(this, "Error", "Invalid data");
        return;
    }
    model->add(i);
}

void ModelView2::accept()
{
    int index = ui.tableView->currentIndex().row();
    Idea i = service.getIdeas()[index];
    
    if (i.getStatus() == "accepted")
    {
		QMessageBox::critical(this, "Error", "No idea selected");
		return;
	}
    
    //model->accept(index);
}