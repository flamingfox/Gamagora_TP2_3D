QT += core
QT += gui

TARGET = Gamagora_TP2_3D
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += C:\Developpement\glm

TEMPLATE = app

SOURCES += main.cpp \
    csg_node.cpp \
    csg_primitive.cpp \
    rayon.cpp \
    lib/vecteur.cpp

HEADERS += \
    csg_node.h \
    csg_primitive.h \
    rayon.h \
    lib/vecteur.h

