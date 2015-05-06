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
    querytools.cpp \
    addweapondialog.cpp \
    weapon.cpp \
    defensecalculatorwindow.cpp

HEADERS  += mainwindow.hpp \
    damagecalculator.hpp \
    damagecalculatorwindow.hpp \
    querytools.hpp \
    addweapondialog.hpp \
    weapon.hpp \
    defensecalculatorwindow.hpp

FORMS    += mainwindow.ui \
    damagecalculatorwindow.ui \
    addweapondialog.ui \
    defensecalculatorwindow.ui

DISTFILES +=
