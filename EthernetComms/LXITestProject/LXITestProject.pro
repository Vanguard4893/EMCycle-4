#-------------------------------------------------
#
# Project created by QtCreator 2019-05-16T10:05:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LXITestProject
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/release/ -lCassLXI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/debug/ -lCassLXI
else:unix: LIBS += -L$$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/ -lCassLXI

INCLUDEPATH += $$PWD/../../Libraries/CassLXI/CassLXI
DEPENDPATH += $$PWD/../../Libraries/CassLXI/CassLXI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/release/libCassLXI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/debug/libCassLXI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/release/CassLXI.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/debug/CassLXI.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../Libraries/CassLXI/build-CassLXI-Desktop_Qt_5_12_0_GCC_64bit-Debug/libCassLXI.a

#LXI
unix:!macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -llxi

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include
