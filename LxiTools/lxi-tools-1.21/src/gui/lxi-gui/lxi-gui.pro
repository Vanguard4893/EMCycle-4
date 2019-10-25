#-------------------------------------------------
#
# Project created by QtCreator 2017-12-31T00:31:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lxi-gui
TEMPLATE = app

isEmpty(SNAPCRAFT) {
    QT += charts
}

!isEmpty(SNAPCRAFT) {
    system("echo \"Machine: `uname -m`\""): ;
    system("if [ \"`uname -m`\" = \"x86_64\" ]; then exit 0 ; else exit 1; fi"): TRIPLET=x86_64-linux-gnu
    system("if [ \"`uname -m`\" = \"i686\" ]; then exit 0 ; else exit 1; fi"): TRIPLET=i386-linux-gnu
    system("if [ \"`uname -m`\" = \"armv7l\" ]; then exit 0 ; else exit 1; fi"): TRIPLET=arm-linux-gnueabihf
    system("if [ \"`uname -m`\" = \"armv8l\" ]; then exit 0 ; else exit 1; fi"): TRIPLET=arm-linux-gnueabihf
    LIBS += -lQt5Charts
    LIBS += -L"$$QT_LIBDIR/$$TRIPLET"
    INCLUDEPATH += $$QT_INCDIR/$$TRIPLET/qt5
}

INCLUDEPATH += $$QT_INCDIR

#LIBS += -llxi ../../libapp.a -lreadline -L"$$QT_LIBDIR"
LIBS += -llxqt -lreadline -L"$$QT_LIBDIR"

CONFIG += c++11

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
        workerthread.cpp

HEADERS += \
        mainwindow.h \
        workerthread.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    lxi-gui.qrc


#LXI
unix:!macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/lib/ -llxi

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/include
