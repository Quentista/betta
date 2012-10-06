#include <QApplication>
#include <equat.h>

int main(int argc, char** argv)
{
    QApplication app (argc, argv);


    Equation Equat1;

    Equat1.resize(400,200);

    Equat1.show();

    return app.exec();
}
