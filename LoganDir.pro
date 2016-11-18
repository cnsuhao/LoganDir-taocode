#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T09:43:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoganDir
TEMPLATE = app


SOURCES += main.cpp\
        qmainwindowwidget.cpp \
    Model/ConfigFile.cpp \
    Model/VideoWidget.cpp \
    View/CradleView.cpp \
    View/MainView.cpp \
    View/DisplayView.cpp \
    View/SettingView.cpp \
    View/Setting/BaseSettingView.cpp \
    View/Setting/UserMgrView.cpp \
    View/Setting/StreamMediaView.cpp \
    View/Setting/InputMgrView.cpp \
    View/Setting/OutputSettingView.cpp \
    View/Setting/NetSettingView.cpp \
    View/Setting/FTPMgrView.cpp \
    View/Setting/LogMgrView.cpp \
    View/SubVideoSwitchView.cpp \
    View/VideoEffectView.cpp \
    View/VideoOptionView.cpp \
    View/VideoAttachView.cpp \
    Model/DragWidget.cpp

HEADERS  += qmainwindowwidget.h \
    Model/ConfigFile.h \
    Model/VideoWidget.h \
    View/CradleView.h \
    View/MainView.h \
    View/DisplayView.h \
    View/SettingView.h \
    View/Setting/BaseSettingView.h \
    View/Setting/UserMgrView.h \
    View/Setting/StreamMediaView.h \
    View/Setting/InputMgrView.h \
    View/Setting/OutputSettingView.h \
    View/Setting/NetSettingView.h \
    View/Setting/FTPMgrView.h \
    View/Setting/LogMgrView.h \
    View/SubVideoSwitchView.h \
    View/VideoEffectView.h \
    View/VideoOptionView.h \
    View/VideoAttachView.h \
    Model/DragWidget.h

RESOURCES += \
    src.qrc
