QT += core
QT -= gui

TARGET = Gamagora_TP2_3D
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += C:\lib

TEMPLATE = app

SOURCES += main.cpp \
    OpBin/opbin.cpp \
    OpBin/opunion.cpp \
    OpBin/opinter.cpp

HEADERS += \
    OpBin/opbin.h \
    OpBin/opunion.h \
    OpBin/opinter.h

