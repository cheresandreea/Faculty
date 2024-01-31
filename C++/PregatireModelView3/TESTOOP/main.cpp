#include "TESTOOP.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Repository.h"
#include "Bill.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo;
    Service service{ repo };
    TESTOOP ui{ service };

    ui.show();
    return a.exec();
}
