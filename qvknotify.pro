#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T00:02:47
#
#-------------------------------------------------

QT       += core gui webkitwidgets

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled6
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mainwindow.cpp \
    dialog.cpp \
    message.cpp \
    users.cpp \
    about.cpp \
    dialogform.cpp

HEADERS  += widget.h \
    mainwindow.h \
    dialog.h \
    message.h \
    users.h \
    about.h \
    dialogform.h \
    error.h

FORMS    += widget.ui \
    mainwindow.ui \
    dialog.ui \
    about.ui \
    dialogform.ui

TRANSLATIONS   += qvknotify_ru_RU.ts \
qvknotify_en_GB.ts
