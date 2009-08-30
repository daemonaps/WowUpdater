/********************************************************************************
** Form generated from reading ui file 'updaterwindow.ui'
**
** Created: Sun Aug 30 07:17:48 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UPDATERWINDOW_H
#define UI_UPDATERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updaterWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *md5_wow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *updaterWindow)
    {
        if (updaterWindow->objectName().isEmpty())
            updaterWindow->setObjectName(QString::fromUtf8("updaterWindow"));
        updaterWindow->resize(384, 323);
        centralWidget = new QWidget(updaterWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        progressBar_2 = new QProgressBar(groupBox_2);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);

        verticalLayout_2->addWidget(progressBar_2);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        md5_wow = new QLineEdit(groupBox_3);
        md5_wow->setObjectName(QString::fromUtf8("md5_wow"));

        verticalLayout_3->addWidget(md5_wow);


        gridLayout->addWidget(groupBox_3, 3, 0, 1, 1);

        updaterWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(updaterWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 384, 25));
        updaterWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(updaterWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        updaterWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(updaterWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        updaterWindow->setStatusBar(statusBar);

        retranslateUi(updaterWindow);
        QObject::connect(pushButton, SIGNAL(released()), updaterWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(updaterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *updaterWindow)
    {
        updaterWindow->setWindowTitle(QApplication::translate("updaterWindow", "APS Updater Version 0.0.2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("updaterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">APS AutoUpdater</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("updaterWindow", "Mise a jour", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("updaterWindow", "T\303\251l\303\251chargement de la mise a jour", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("updaterWindow", "Recherche de mise a jour", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("updaterWindow", "T\303\251l\303\251chargement des infos de mise a jour ...", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("updaterWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("updaterWindow", "Debug", 0, QApplication::UnicodeUTF8));
        md5_wow->setText(QApplication::translate("updaterWindow", "Contenu md( du fichier wow.exe ...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(updaterWindow);
    } // retranslateUi

};

namespace Ui {
    class updaterWindow: public Ui_updaterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATERWINDOW_H
