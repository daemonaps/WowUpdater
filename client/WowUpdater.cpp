#include "WowUpdater.h"
#include "ui_updaterwindow.h"

WowUpdater::WowUpdater(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    m_md5wow = md5File("wow.exe");
    md5_wow->setText(m_md5wow);
}

WowUpdater::~WowUpdater()
{

}

QString WowUpdater::md5File(QString filename)
{
    QFile *wow = new QFile(filename);
    if(wow->open(QIODevice::ReadOnly))
    {
        QString content = wow->readAll().constData();
        const char* wowData = content.toStdString().c_str();

        //Calcul du md5
        md5_state_t state;
        md5_byte_t digest[16];
        char hex_output[16*2 + 1];
        int di;

        md5_init(&state);
        md5_append(&state, (const md5_byte_t *)wowData, strlen(wowData));
        md5_finish(&state, digest);
        for (di = 0; di < 16; ++di)
            sprintf(hex_output + di * 2, "%02x", digest[di]);
        return QString(hex_output);
    }
    else
    {
        //Impossible d'ouvrir le fichier
        return QString("");
    }
}

void WowUpdater::downloadFile()
{

}
