#include <QApplication>
#include <Equat.h>

int main(int argc, char** argv)
{
    QApplication app (argc, argv);


    Equation equat;

    equat.resize(400,200);
    equat.show();

    return app.exec();
}
