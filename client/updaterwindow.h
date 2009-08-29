#ifndef UPDATERWINDOW_H
#define UPDATERWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class updaterWindow;
}

class updaterWindow : public QMainWindow
{
    Q_OBJECT

public:
    updaterWindow(QWidget *parent = 0);
    ~updaterWindow();

private:
    Ui::updaterWindow *ui;
};

#endif // UPDATERWINDOW_H
