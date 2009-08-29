#ifndef UPDATERWINDOW_H
#define UPDATERWINDOW_H

#include <QtGui/QMainWindow>

#include "ui_updaterwindow.h"
#include "updater.h"

namespace Ui
{
    class updaterWindow;
}

class updaterWindow : public QMainWindow, private Ui::updaterWindow, private updater
{
    Q_OBJECT

public:
    updaterWindow(QWidget *parent = 0);
    ~updaterWindow();

private:

};

#endif // UPDATERWINDOW_H
