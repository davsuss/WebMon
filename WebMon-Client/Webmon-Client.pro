#-------------------------------------------------
#
# Project created by QtCreator 2013-11-11T11:06:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Webmon-FinalProject
TEMPLATE = app
QT += network

SOURCES += main.cpp\
        mainwindow.cpp \
    battleform.cpp \
    datastore.cpp \
    pokemon.cpp \
    controller.cpp \
    logindialog.cpp \
    waitingform.cpp

HEADERS  += mainwindow.h \
    battleform.h \
    datastore.h \
    pokemon.h \
    controller.h \
    logindialog.h \
    waitingform.h \
    Structs.h

FORMS    += mainwindow.ui \
    battleform.ui \
    logindialog.ui \
    waitingform.ui
