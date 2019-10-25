#-------------------------------------------------
#
# Project created by QtCreator 2019-02-26T11:08:14
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialCommsAsync
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Libraries
unix:!macx: LIBS += -L$$PWD/../../Libraries/CassSerial/build-CassSerial-Desktop_Qt_5_12_0_GCC_64bit-Debug/ -lCassSerial

INCLUDEPATH += $$PWD/../../Libraries/CassSerial/CassSerial
DEPENDPATH += $$PWD/../../Libraries/CassSerial/CassSerial

unix:!macx: PRE_TARGETDEPS += $$PWD/../../Libraries/CassSerial/build-CassSerial-Desktop_Qt_5_12_0_GCC_64bit-Debug/libCassSerial.a
