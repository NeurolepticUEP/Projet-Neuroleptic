#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T16:06:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = moteur
TEMPLATE = app

SOURCES += src/main.cpp\
    src/window.cpp \
    src/data_maker.cpp \
    src/engine_class/engine_graphic.cpp \
    src/engine_class/engine_interaction.cpp \
    src/engine_class/rendernode.cpp \
    src/data_class/scenegraph.cpp \
    src/engine_class/world.cpp \
    src/data_class/graphic/camera.cpp \
    src/data_class/graphic/mesh.cpp \
    src/data_class/graphic/shader.cpp \
    src/objloading.cpp

HEADERS  += \
    src/gl_include.h \
    src/window.h \
    src/data_maker.h \
    src/sintracker.h \
    src/engine_class/engine_abstract.h \
    src/engine_class/engine_graphic.h \
    src/engine_class/engine_interaction.h \
    src/data_class/instance.h \
    src/engine_class/rendernnode.h \
    src/data_class/scenegraph.h \
    src/engine_class/world.h \
    src/data_class/graphic/camera.h \
    src/data_class/graphic/mesh.h \
    src/data_class/graphic/shader.h \
    src/data_class/world_data.h \
    src/data_class/state.h \
    src/data_class/instance_vector.h \
    src/data_class/graphic/bindable.h \
    src/data_class/graphic/drawable.h \
    src/objloading.h

FORMS    +=


INCLUDEPATH += $${PWD}/lib/VRPN/src
LIBS += -L$${PWD}/lib/VRPN/ -lvrpn -lvrpnserver -lws2_32


QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    shader/display.frag \
    shader/display.vert

DISTFILES +=
