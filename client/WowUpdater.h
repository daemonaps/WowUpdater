#ifndef UPDATERWINDOW_H
#define UPDATERWINDOW_H

#include <QtGui/QMainWindow>
#include <QFile>

#include "ui_updaterwindow.h"
#include "md5.h"

namespace Ui
{
    class updaterWindow;
}

class WowUpdater : public QMainWindow, private Ui::updaterWindow
{
    Q_OBJECT

    public:
        WowUpdater(QWidget *parent = 0);
        ~WowUpdater();

    protected:
        QString md5File(QString filename);
        void downloadFile();

        QString m_md5wow;


};

#endif // UPDATERWINDOW_H
