QT += core
QT += gui

TARGET = Gamagora_TP2_3D
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += C:\lib
INCLUDEPATH += C:\Developpement\glm
INCLUDEPATH += C:\librairie\glm

TEMPLATE = app


CONFIG  += c++11


SOURCES += main.cpp \
    csg/csg_sphere.cpp \
    sphere.cpp \
    rendu/camera.cpp \
    rendu/rayon.cpp \
    OpBin/opbin.cpp \
    OpBin/opunion.cpp \
    OpBin/opinter.cpp \
    csg_node.cpp \
    csg_primitive.cpp \
    lib/vecteur.cpp

HEADERS += \
    csg/csg_sphere.h \
    sphere.h \
    rendu/camera.h \
    rendu/rayon.h \
    OpBin/opbin.h \
    OpBin/opunion.h \
    OpBin/opinter.h \
    csg_node.h \
    csg_primitive.h \
    lib/vecteur.h
