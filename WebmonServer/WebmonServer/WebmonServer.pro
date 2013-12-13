#-------------------------------------------------
#
# Project created by QtCreator 2013-11-25T22:49:48
#
#-------------------------------------------------

QT       += core
QT       += sql
QT       -= gui
QT       += network

TARGET = WebmonServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    databaseConversation.cpp \
    gamemechanics.cpp \
    server.cpp

HEADERS += \
    databaseConversation.h \
    gamemechanics.h \
    server.h