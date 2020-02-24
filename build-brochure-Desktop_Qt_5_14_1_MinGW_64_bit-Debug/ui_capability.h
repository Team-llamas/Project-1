/********************************************************************************
** Form generated from reading UI file 'capability.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPABILITY_H
#define UI_CAPABILITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_capability
{
public:
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser;
    QPushButton *capability_2;
    QLabel *header;
    QLabel *bannerPic;
    QPushButton *home;
    QTextBrowser *textBrowser_2;
    QPushButton *maint;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *capability)
    {
        if (capability->objectName().isEmpty())
            capability->setObjectName(QString::fromUtf8("capability"));
        capability->resize(903, 802);
        textBrowser_3 = new QTextBrowser(capability);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(570, 430, 256, 131));
        textBrowser = new QTextBrowser(capability);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 430, 256, 141));
        capability_2 = new QPushButton(capability);
        capability_2->setObjectName(QString::fromUtf8("capability_2"));
        capability_2->setEnabled(false);
        capability_2->setGeometry(QRect(150, 10, 91, 31));
        header = new QLabel(capability);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(10, 400, 211, 31));
        QFont font;
        font.setPointSize(12);
        header->setFont(font);
        bannerPic = new QLabel(capability);
        bannerPic->setObjectName(QString::fromUtf8("bannerPic"));
        bannerPic->setGeometry(QRect(30, 50, 801, 341));
        bannerPic->setFocusPolicy(Qt::StrongFocus);
        bannerPic->setPixmap(QPixmap(QString::fromUtf8(":/pics/science-in-hd-1WBN-JKSmKI-unsplash.jpg")));
        bannerPic->setScaledContents(true);
        bannerPic->setMargin(0);
        bannerPic->setOpenExternalLinks(false);
        home = new QPushButton(capability);
        home->setObjectName(QString::fromUtf8("home"));
        home->setEnabled(true);
        home->setGeometry(QRect(30, 10, 91, 31));
        textBrowser_2 = new QTextBrowser(capability);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(290, 430, 256, 151));
        maint = new QPushButton(capability);
        maint->setObjectName(QString::fromUtf8("maint"));
        maint->setGeometry(QRect(270, 10, 91, 31));
        label = new QLabel(capability);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 580, 251, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pics/fatma-hatam-6-p_qnVa3zU-unsplash.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(capability);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 590, 251, 191));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pics/xtra-inc-bhXQcYqH4fc-unsplash.jpg")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(capability);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(570, 570, 251, 221));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pics/keri-liwi-SSXCiGKYQQE-unsplash.jpg")));
        label_3->setScaledContents(true);

        retranslateUi(capability);

        QMetaObject::connectSlotsByName(capability);
    } // setupUi

    void retranslateUi(QDialog *capability)
    {
        capability->setWindowTitle(QCoreApplication::translate("capability", "Dialog", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("capability", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Using the latest advances in wireless communication technology, your RoboDetector can be remotely controlled in a 5 km radius with 1-2 ms latency.</span></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("capability", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">With state of the art LIDAR and deep wave emitters, the RoboDetector can scan depths up to 30 m below ground*.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">*Tested on a paved concrete road in fair conditions.</span></p></body><"
                        "/html>", nullptr));
        capability_2->setText(QCoreApplication::translate("capability", "Capability", nullptr));
        header->setText(QCoreApplication::translate("capability", "Customer Testimonials", nullptr));
        bannerPic->setText(QString());
        home->setText(QCoreApplication::translate("capability", "Home", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("capability", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Hybrid track wheels combined with carbon fiber casing lets your RoboDetector travel across any terrain imaginable. From dirt and gravel paths to the urban sprawl, your RoboDetector has you covered.</span></p></body></html>", nullptr));
        maint->setText(QCoreApplication::translate("capability", "Maintanence", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class capability: public Ui_capability {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPABILITY_H
