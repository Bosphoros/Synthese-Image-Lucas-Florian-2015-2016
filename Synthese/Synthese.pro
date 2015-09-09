#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T18:14:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Synthese

TEMPLATE = app


SOURCES += main.cpp \
    mesh.cpp \
    meshbuilder.cpp \
    terrainimage.cpp \
    terrain.cpp \
    mathutils.cpp \
    foncteurwarp.cpp \
    noise.cpp \
    octave.cpp \
    terrainoctaves.cpp \
    smoothnoise.cpp \
    ray.cpp

HEADERS += \
    mesh.h \
    meshbuilder.h \
    terrain.h \
    terrainimage.h \
    mathutils.h \
    foncteurwarp.h \
    noise.h \
    octave.h \
    terrainoctaves.h \
    smoothnoise.h \
    ray.h
