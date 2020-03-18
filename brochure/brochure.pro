QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += sql

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    capability.cpp \
    home.cpp \
    login.cpp \
    main.cpp \
<<<<<<< Updated upstream
    maint.cpp \
    testimonial.cpp
=======
    searchdatabase.cpp
>>>>>>> Stashed changes

HEADERS += \
    capability.h \
    home.h \
    login.h \
<<<<<<< Updated upstream
    maint.h \
    testimonial.h
=======
    searchdatabase.h
>>>>>>> Stashed changes

FORMS += \
    capability.ui \
    home.ui \
    login.ui \
<<<<<<< Updated upstream
    maint.ui \
    testimonial.ui
=======
    searchdatabase.ui
>>>>>>> Stashed changes

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../Project-1-insurance/Project-1-insurance/brochure/images.qrc \
    images.qrc
