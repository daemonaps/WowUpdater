#include <QtGui/QApplication>
#include "WowUpdater.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WowUpdater w;
    w.show();
    return a.exec();
}
