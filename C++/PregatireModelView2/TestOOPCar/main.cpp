#include "TestOOPCar.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    

    Repository repo;
    Service service(repo);
    TestOOPCar w{service};

    w.show();
    return a.exec();
}
