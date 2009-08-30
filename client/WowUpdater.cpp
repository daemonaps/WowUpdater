#include "WowUpdater.h"
#include "ui_updaterwindow.h"

WowUpdater::WowUpdater(QWidget *parent)
    : QMainWindow(parent)
{
    m_step = INIT;
    setupUi(this);
    m_md5wow = md5File("wow.exe");
    md5_wow->setText(m_md5wow);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
         connect(manager, SIGNAL(finished(QNetworkReply*)),
                 this, SLOT(slotRequestFinished(QNetworkReply*)));

    m_step = DOWNLOAD_PATCHLIST;
    downloadFile("http://launcheraps.free.fr/updater/info.php",manager);
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

void WowUpdater::downloadFile(QString url,QNetworkAccessManager *manager)
{
    m_fileDl = new QFile ( QString("fichier") );
    m_fileDl->open(QIODevice::ReadWrite);

    if(manager == NULL)
    {
         manager = new QNetworkAccessManager(this);
         connect(manager, SIGNAL(finished(QNetworkReply*)),
                 this, SLOT(slotRequestFinished(QNetworkReply*)));
    }

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-Agent", m_md5wow.toStdString().c_str());
    manager->get(request);

}

//Slots
void WowUpdater::slotReadyRead()
{
    QNetworkReply* reply =qobject_cast<QNetworkReply *>(sender());
    m_fileDl->write( reply->readAll() );
}

void WowUpdater::slotError(QNetworkReply::NetworkError)
{

}

void WowUpdater::slotRequestFinished(QNetworkReply* reply)
{
    const char * data = reply->readAll().constData();

    switch(m_step)
    {

        case DOWNLOAD_PATCHLIST:
            m_fileDl->write(data);
            m_fileDl->close();
            lblDebug->setText("Recherche de mise a jour finie");
            m_step = PATCHLIST_DOWNLOADED;
            return;
        case DOWNLOAD_MAJ:
            m_fileDl->write(data);
            m_fileDl->close();
            lblDebug->setText("Mise a jour téléchargée");
            m_step = MAJ_DOWNLOADED;
            return;
        case INIT:
        case PATCHLIST_DOWNLOADED:
        case MAJ_DOWNLOADED:
            lblDebug->setText("Erreur ...");
            return;
        default:
            return;
    }
}
