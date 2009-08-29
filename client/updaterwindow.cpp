#include "updaterwindow.h"
#include "ui_updaterwindow.h"

updaterWindow::updaterWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::updaterWindow)
{
    ui->setupUi(this);
}

updaterWindow::~updaterWindow()
{
    delete ui;
}
