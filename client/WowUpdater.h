#ifndef UPDATERWINDOW_H
#define UPDATERWINDOW_H

#include <QtGui/QMainWindow>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "ui_updaterwindow.h"
#include "md5.h"

namespace Ui
{
    class updaterWindow;
}

enum Etape {INIT = 0,
                DOWNLOAD_PATCHLIST,
                PATCHLIST_DOWNLOADED,
                DOWNLOAD_MAJ,
                MAJ_DOWNLOADED};

class WowUpdater : public QMainWindow, private Ui::updaterWindow
{

    Q_OBJECT

    public:
        WowUpdater(QWidget *parent = 0);
        ~WowUpdater();

    protected slots:
        void slotReadyRead();
        void slotError(QNetworkReply::NetworkError);
        void slotRequestFinished(QNetworkReply*);

    protected:
        QString md5File(QString filename);
        void downloadFile(QString url,QNetworkAccessManager *manager = NULL);

    private:
        QString m_md5wow;
        int m_step;
        QFile* m_fileDl;

};

#endif // UPDATERWINDOW_H
