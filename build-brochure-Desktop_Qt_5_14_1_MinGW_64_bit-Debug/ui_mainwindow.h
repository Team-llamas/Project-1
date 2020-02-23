/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *bannerPic;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QLabel *scanPic;
    QTextBrowser *textBrowser_2;
    QLabel *label;
    QTextBrowser *textBrowser_3;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menuHome;
    QMenu *menuMaintanance_Plans;
    QMenu *menuCapabilities;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(837, 686);
        MainWindow->setAnimated(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bannerPic = new QLabel(centralwidget);
        bannerPic->setObjectName(QString::fromUtf8("bannerPic"));
        bannerPic->setGeometry(QRect(10, 0, 801, 341));
        bannerPic->setFocusPolicy(Qt::StrongFocus);
        bannerPic->setPixmap(QPixmap(QString::fromUtf8(":/pics/science-in-hd-1WBN-JKSmKI-unsplash.jpg")));
        bannerPic->setScaledContents(true);
        bannerPic->setMargin(0);
        bannerPic->setOpenExternalLinks(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 340, 211, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 370, 256, 131));
        scanPic = new QLabel(centralwidget);
        scanPic->setObjectName(QString::fromUtf8("scanPic"));
        scanPic->setGeometry(QRect(0, 480, 261, 141));
        scanPic->setPixmap(QPixmap(QString::fromUtf8(":/pics/fatma-hatam-6-p_qnVa3zU-unsplash.jpg")));
        scanPic->setScaledContents(true);
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(290, 370, 256, 151));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 520, 261, 121));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pics/xtra-inc-bhXQcYqH4fc-unsplash.jpg")));
        label->setScaledContents(true);
        textBrowser_3 = new QTextBrowser(centralwidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(560, 370, 256, 131));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(560, 480, 261, 151));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pics/keri-liwi-SSXCiGKYQQE-unsplash.jpg")));
        label_3->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 837, 21));
        menuHome = new QMenu(menubar);
        menuHome->setObjectName(QString::fromUtf8("menuHome"));
        menuHome->setAutoFillBackground(false);
        menuMaintanance_Plans = new QMenu(menubar);
        menuMaintanance_Plans->setObjectName(QString::fromUtf8("menuMaintanance_Plans"));
        menuCapabilities = new QMenu(menubar);
        menuCapabilities->setObjectName(QString::fromUtf8("menuCapabilities"));
        menuCapabilities->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QFont font;
        font.setPointSize(12);
        statusbar->setFont(font);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHome->menuAction());
        menubar->addAction(menuCapabilities->menuAction());
        menubar->addAction(menuMaintanance_Plans->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bannerPic->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "So What Can the RoboDetector 3000 Do?", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">With state-of-the-art LIDAR and deep penatration wave emitters, the RoboDetector</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">can scan depths up to 30m below ground*.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
        scanPic->setText(QString());
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Hybrid tract wheels combined with carbon fiber casing let's your RoboDetector travel across any kind of terrain imaginable. From dirt and gravel paths to the urban sprawl, your RoboDetector has you covered.</span></p></body></html>", nullptr));
        label->setText(QString());
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Using the latest advances in wireless communications technology, your RoboDetector can be remotely controled up in a 5 km radius with 1-2 ms latency.</span></p></body></html>", nullptr));
        label_3->setText(QString());
        menuHome->setTitle(QCoreApplication::translate("MainWindow", "Home", nullptr));
        menuMaintanance_Plans->setTitle(QCoreApplication::translate("MainWindow", "Maintanance Plans", nullptr));
        menuCapabilities->setTitle(QCoreApplication::translate("MainWindow", "Capabilities", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
