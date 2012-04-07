#include <QtGui/QApplication>
#include "qloozer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoozer w;
    w.show();

    return a.exec();
}
