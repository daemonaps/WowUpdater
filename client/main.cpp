#include <QtGui/QApplication>
#include "updaterwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    updaterWindow w;
    w.show();
    return a.exec();
}
