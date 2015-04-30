#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T01:49:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MH4U-Tool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    damagecalculator.cpp \
    damagecalculatorwindow.cpp \
    querytools.cpp

HEADERS  += mainwindow.hpp \
    damagecalculator.hpp \
    damagecalculatorwindow.hpp \
    querytools.hpp

FORMS    += mainwindow.ui \
    damagecalculatorwindow.ui

DISTFILES +=
