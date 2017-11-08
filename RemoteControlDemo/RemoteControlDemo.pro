#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T13:29:23
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RemoteControlDemo
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
    mainpresenter.cpp

HEADERS += \
        mainwindow.h \
    mainpresenter.h

FORMS += \
        mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libRemoteControl/release/ -llibRemoteControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libRemoteControl/debug/ -llibRemoteControl

INCLUDEPATH += $$PWD/../libRemoteControl
DEPENDPATH += $$PWD/../libRemoteControl

message ($$PWD)


#unix:!macx: LIBS += -L$$PWD/../build-libRemoteControl-Desktop_Qt_5_9_2_GCC_64bit-Release/ -llibRemoteControl
unix:!macx: LIBS += -L$$PWD/../build-libRemoteControl-Desktop_Qt_5_9_2_GCC_64bit-Debug/ -llibRemoteControl

INCLUDEPATH += $$PWD/../libRemoteControl
DEPENDPATH += $$PWD/../libRemoteControl

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../laserRemoteControl/release/ -llaserRemoteControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../laserRemoteControl/debug/ -llaserRemoteControl
else:unix:!macx: LIBS += -L$$PWD/../../laserRemoteControl/ -llaserRemoteControl

INCLUDEPATH += $$PWD/../../laserRemoteControl
DEPENDPATH += $$PWD/../../laserRemoteControl
