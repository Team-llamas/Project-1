/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *bannerPic;
    QLabel *header;
    QTextBrowser *textBrowser;
    QLabel *pic1;
    QTextBrowser *textBrowser_2;
    QLabel *pic2;
    QTextBrowser *textBrowser_3;
    QLabel *pic3;
    QPushButton *home;
    QPushButton *capability;
    QPushButton *maint;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 897);
        MainWindow->setAnimated(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bannerPic = new QLabel(centralwidget);
        bannerPic->setObjectName(QString::fromUtf8("bannerPic"));
        bannerPic->setGeometry(QRect(20, 50, 801, 341));
        bannerPic->setFocusPolicy(Qt::StrongFocus);
        bannerPic->setPixmap(QPixmap(QString::fromUtf8(":/pics/science-in-hd-1WBN-JKSmKI-unsplash.jpg")));
        bannerPic->setScaledContents(true);
        bannerPic->setMargin(0);
        bannerPic->setOpenExternalLinks(false);
        header = new QLabel(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(10, 400, 211, 31));
        QFont font;
        font.setPointSize(12);
        header->setFont(font);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 430, 256, 131));
        pic1 = new QLabel(centralwidget);
        pic1->setObjectName(QString::fromUtf8("pic1"));
        pic1->setGeometry(QRect(10, 560, 251, 271));
        pic1->setPixmap(QPixmap(QString::fromUtf8(":/pics/hayley-wagner-7UIpoiARc_8-unsplash.jpg")));
        pic1->setScaledContents(true);
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(290, 430, 256, 151));
        pic2 = new QLabel(centralwidget);
        pic2->setObjectName(QString::fromUtf8("pic2"));
        pic2->setGeometry(QRect(290, 570, 261, 261));
        pic2->setPixmap(QPixmap(QString::fromUtf8(":/pics/michael-dam-mEZ3PoFGs_k-unsplash.jpg")));
        pic2->setScaledContents(true);
        textBrowser_3 = new QTextBrowser(centralwidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(570, 430, 256, 131));
        pic3 = new QLabel(centralwidget);
        pic3->setObjectName(QString::fromUtf8("pic3"));
        pic3->setGeometry(QRect(570, 550, 261, 291));
        pic3->setPixmap(QPixmap(QString::fromUtf8(":/pics/anjo-clacino-YIMASa67nKU-unsplash.jpg")));
        pic3->setScaledContents(true);
        home = new QPushButton(centralwidget);
        home->setObjectName(QString::fromUtf8("home"));
        home->setEnabled(false);
        home->setGeometry(QRect(20, 10, 91, 31));
        capability = new QPushButton(centralwidget);
        capability->setObjectName(QString::fromUtf8("capability"));
        capability->setEnabled(true);
        capability->setGeometry(QRect(140, 10, 91, 31));
        maint = new QPushButton(centralwidget);
        maint->setObjectName(QString::fromUtf8("maint"));
        maint->setGeometry(QRect(260, 10, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 850, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setFont(font);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bannerPic->setText(QString());
        header->setText(QCoreApplication::translate("MainWindow", "Customer Testimonials", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;I love my RoboDetector! (Please send help they are forcing me to say this)&quot;</span></p></body></html>", nullptr));
        pic1->setText(QString());
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;The RoboDetector helps me in my day to day life (read as: get rid of anyone who annoys me that day)!&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
        pic2->setText(QString());
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">&quot;Sure, I love this product whatever it is!&quot;</span></p></body></html>", nullptr));
        pic3->setText(QString());
        home->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        capability->setText(QCoreApplication::translate("MainWindow", "Capability", nullptr));
        maint->setText(QCoreApplication::translate("MainWindow", "Maintanence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
