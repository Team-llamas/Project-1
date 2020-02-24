#-------------------------------------------------
#
# Project created by QtCreator 2020-02-11T22:22:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        capability.cpp \
#        home.cpp \
    home.cpp \
    database.cpp \
    customerinfotype.cpp \
    inputcustomerdata.cpp

HEADERS += \
        capability.h \
        mainwindow.h \
    home.h \
    customerinfotype.h \
    utilities.h \
    database.h \
    inputcustomerdata.h

FORMS += \
        mainwindow.ui \
        capability.ui \
        home.ui \
    inputcustomerdata.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    database.txt
