#include "annatto.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Annatto w;
    w.show();
    return a.exec();
}
