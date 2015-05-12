#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T01:49:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MH4U-Tool
TEMPLATE = app


SOURCES += src/Sources/main.cpp\
    src/Sources/mainwindow.cpp \
    src/Sources/damagecalculator.cpp \
    src/Sources/damagecalculatorwindow.cpp \
    src/Sources/querytools.cpp \
    src/Sources/addweapondialog.cpp \
    src/Sources/weapon.cpp \
    src/Sources/defensecalculatorwindow.cpp \

HEADERS  += src/Headers/mainwindow.hpp \
    src/Headers/damagecalculator.hpp \
    src/Headers/damagecalculatorwindow.hpp \
    src/Headers/querytools.hpp \
    src/Headers/addweapondialog.hpp \
    src/Headers/weapon.hpp \
    src/Headers/defensecalculatorwindow.hpp \

FORMS    += src/Forms/mainwindow.ui \
    src/Forms/damagecalculatorwindow.ui \
    src/Forms/addweapondialog.ui \
    src/Forms/defensecalculatorwindow.ui \

DISTFILES +=
