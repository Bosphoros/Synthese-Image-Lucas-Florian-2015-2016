#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T18:14:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Synthese

TEMPLATE = app
CONFIG += c++11
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp


SOURCES += main.cpp \
    mesh.cpp \
    meshbuilder.cpp \
    terrainimage.cpp \
    terrain.cpp \
    terrainnoise.cpp \
    terrainnoisesmultiples.cpp \
    terraintest.cpp \
    mathutils.cpp \
    smoothnoise.cpp \
    ray.cpp \
    camera.cpp \
    vector2d.cpp \
    vector3d.cpp \
    box.cpp \
    plane.cpp \
    sphere.cpp \
    csgnode.cpp \
    csgunaire.cpp \
    csgbinaire.cpp \
    csgprimitive.cpp \
    csgsphere.cpp \
    csgbox.cpp \
    csgunion.cpp \
    csgintersection.cpp \
    csgdifference.cpp \
    csgtranslation.cpp \
    csgrotation.cpp \
    csgscale.cpp \
    matrix3x3.cpp \
    tableauvoxel.cpp

HEADERS += \
    mesh.h \
    meshbuilder.h \
    terrain.h \
    terrainimage.h \
    terrainnoise.h \
    terrainnoisesmultiples.h \
    terraintest.h \
    mathutils.h \
    smoothnoise.h \
    ray.h \
    camera.h \
    vector2d.h \
    vector3d.h \
    box.h \
    plane.h \
    sphere.h \
    csgnode.h \
    csgunaire.h \
    csgbinaire.h \
    csgprimitive.h \
    csgsphere.h \
    csgbox.h \
    csgunion.h \
    csgintersection.h \
    csgdifference.h \
    csgtranslation.h \
    csgrotation.h \
    csgscale.h \
    matrix3x3.h \
    tableauvoxel.h
