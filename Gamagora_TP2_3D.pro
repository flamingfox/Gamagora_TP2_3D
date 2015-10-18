QT += core
QT += gui


TARGET = Gamagora_TP2_3D
CONFIG += console
CONFIG -= app_bundle

LIBS += -lopengl32 -lglu32

INCLUDEPATH += C:\lib
INCLUDEPATH += C:\Developpement\glm
INCLUDEPATH += C:\librairie\glm


QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

TEMPLATE = app

CONFIG  += c++11

QT += opengl

SOURCES += main.cpp \
    csg/csg_sphere.cpp \
    lib/sphere.cpp \
    rendu/camera.cpp \
    rendu/rayon.cpp \
    OpBin/opbin.cpp \
    OpBin/opunion.cpp \
    OpBin/opinter.cpp \
    csg/csg_primitive.cpp \
    lib/vecteur.cpp \
    OpBin/opdif.cpp \
    opUnaire/opt.cpp \
    opUnaire/opr.cpp \
    opUnaire/ops.cpp \
    lib/box.cpp \
    csg/csg_box.cpp \
    node.cpp \
    opUnaire/opunaire.cpp \
    lib/voxel.cpp \
    rendu/myglwidget.cpp \
    rendu/mywindow.cpp \
    rendu/scene.cpp \
    si/si_sphere.cpp \
    lib/interpolation.cpp \
    lib/noisegenerator.cpp \
    lib/nrw.cpp \
    terrain/terrain.cpp \
    terrain/terrainnoise.cpp \
    terrain/terraintab.cpp \
    rendu/colorgradient.cpp \
    si/si_primitive.cpp \
    si/opmelange.cpp \
    si/si_box.cpp


HEADERS += \
    csg/csg_sphere.h \
    lib/sphere.h \
    rendu/camera.h \
    rendu/rayon.h \
    OpBin/opbin.h \
    OpBin/opunion.h \
    OpBin/opinter.h \
    csg/csg_primitive.h \
    lib/vecteur.h \
    OpBin/opdif.h \
    opUnaire/opt.h \
    opUnaire/opr.h \
    opUnaire/ops.h \
    lib/box.h \
    csg/csg_box.h \
    node.h \
    opUnaire/opunaire.h \
    lib/voxel.h \
    rendu/myglwidget.h \
    rendu/mywindow.h \
    textures/herbe.jpg \
    rendu/scene.h \
    si/si_sphere.h \
    lib/interpolation.h \
    lib/noisegenerator.h \
    lib/nrw.h \
    lib/parametres.h \
    terrain/terrain.h \
    terrain/terrainnoise.h \
    terrain/terraintab.h \
    rendu/colorgradient.h \
    si/si_primitive.h \
    si/opmelange.h \
    si/si_box.h
