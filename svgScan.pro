#-------------------------------------------------
#
# Project created by QtCreator 2019-03-09T15:32:04
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg

TARGET = svgScan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    svgwindow.cpp \
    svgwidget.cpp

HEADERS  += mainwindow.h \
    svgwindow.h \
    svgwidget.h

FORMS    += mainwindow.ui
