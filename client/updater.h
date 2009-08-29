#ifndef UPDATER_H
#define UPDATER_H

#include <QString>
#include <QFile>

#include "md5.h"

class updater
{
    public:
        updater();

    protected:
        QString md5File(QString filename);
        void downloadFile();

        QString m_md5wow;
};

#endif // UPDATER_H
