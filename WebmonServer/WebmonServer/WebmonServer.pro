#-------------------------------------------------
#
# Project created by QtCreator 2013-11-25T22:49:48
#
#-------------------------------------------------
CONFIG   += console
QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebmonServer
TEMPLATE = app

SOURCES += main.cpp \
    databaseConversation.cpp \
    gamemechanics.cpp \
    server.cpp \
    trainer.cpp \
    dialog.cpp

HEADERS += \
    databaseConversation.h \
    gamemechanics.h \
    server.h \
    trainer.h \
    constants.h \
    dialog.h


# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneserver
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS fortuneserver.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneserver
INSTALLS += target sources


 target.path = $$[QT_INSTALL_EXAMPLES]/xmlpatterns/schema
 sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.xq *.html files
 sources.path = $$[QT_INSTALL_EXAMPLES]/xmlpatterns/schema
 INSTALLS += target sources
