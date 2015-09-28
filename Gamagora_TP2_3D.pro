QT += core
QT -= gui

TARGET = Gamagora_TP2_3D
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


CONFIG  += c++11
INCLUDEPATH += C:/librairie/glm


SOURCES += main.cpp \
    csg/csg_sphere.cpp \
    sphere.cpp \
    rendu/camera.cpp \
    rendu/rayon.cpp

HEADERS += \
    csg/csg_sphere.h \
    sphere.h \
    rendu/camera.h \
    rendu/rayon.h

