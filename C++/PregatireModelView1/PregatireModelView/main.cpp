#include "PregatireModelView.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "UserWindow.h"
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo{};
    Service service{ repo };
    IssueModel i{ repo };

   // UserWindow u{ &i, service };

    for (auto user : repo.getUsers())
    {
        UserWindow* u = nullptr;
        if(user.getType() == "tester")
            u = new UserWindow{ &i, service, user.getName(), true};
        else u = new UserWindow{ &i, service, user.getName() };
        u->setWindowTitle(QString::fromStdString(user.getName() + " " + user.getType()));
        u->show();
    }
   // u.show();
    return a.exec();
}
