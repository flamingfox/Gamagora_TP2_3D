QT += core
QT += gui

TARGET = Gamagora_TP2_3D
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += C:\lib
INCLUDEPATH += C:\Developpement\glm

TEMPLATE = app

SOURCES += main.cpp \
    OpBin/opbin.cpp \
    OpBin/opunion.cpp \
    OpBin/opinter.cpp \
    csg_node.cpp \
    csg_primitive.cpp \
    rayon.cpp \
    lib/vecteur.cpp

HEADERS += \
    OpBin/opbin.h \
    OpBin/opunion.h \
    OpBin/opinter.h \
    csg_node.h \
    csg_primitive.h \
    rayon.h \
    lib/vecteur.h
