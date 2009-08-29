#include "updaterwindow.h"
#include "ui_updaterwindow.h"

updaterWindow::updaterWindow(QWidget *parent)
    : QMainWindow(parent),updater()
{
    setupUi(this);
    md5_wow->setText(m_md5wow);
}

updaterWindow::~updaterWindow()
{

}
