#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T14:53:25
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = operational
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    add_marker.cpp

HEADERS  += mainwindow.h \
    add_marker.h

FORMS    += mainwindow.ui \
    add_marker.ui

RESOURCES += \
    map.qrc
