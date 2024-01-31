#include "ModelView2.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "Model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo{};
    Service service{ repo };
    Model model{ repo };

    for (auto writer : service.getWriters())
    {
        ModelView2* w = new ModelView2{ &model, writer.getName(), writer.getExpertise(), service };

        w->setWindowTitle(QString::fromStdString(writer.getName()));
        w->show();
    }
 
    return a.exec();
}
