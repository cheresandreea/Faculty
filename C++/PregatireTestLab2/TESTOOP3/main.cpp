#include "TESTOOP3.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Repository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo;
    Service serv(repo);

    TESTOOP3 ui{serv};
    ui.show();
    return a.exec();
}
