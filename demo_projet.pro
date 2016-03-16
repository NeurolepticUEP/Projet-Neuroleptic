#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T16:06:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = moteur
TEMPLATE = app

SOURCES += main.cpp\
    window.cpp \
    sintracker.cpp \
    data_maker.cpp \
    engine_class/engine_graphic.cpp \
    engine_class/engine_interaction.cpp \
    engine_class/rendernode.cpp \
    data_class/scenegraph.cpp \
    engine_class/world.cpp \
    data_class/graphic/camera.cpp \
    data_class/graphic/mesh.cpp \
    data_class/graphic/shader.cpp \
    data_class/graphic/texture.cpp

HEADERS  += \
    gl_include.h \
    window.h \
    data_maker.h \
    sintracker.h \
    engine_class/engine_abstract.h \
    engine_class/engine_graphic.h \
    engine_class/engine_interaction.h \
    data_class/instance.h \
    engine_class/rendernnode.h \
    data_class/scenegraph.h \
    engine_class/world.h \
    data_class/graphic/camera.h \
    data_class/graphic/mesh.h \
    data_class/graphic/shader.h \
    data_class/graphic/texture.h \
    data_class/world_data.h \
    data_class/state.h \
    data_class/instance_vector.h \
    data_class/graphic/bindable.h \
    data_class/graphic/drawable.h

FORMS    +=

INCLUDEPATH += "../src/lib/GLEW/src" "../src/lib/VRPN/src"
LIBS += -L"../src/lib/GLEW/lib" -L"../src/lib/VRPN/lib" -lglew32s -lopengl32

QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    display.frag \
    display.vert

DISTFILES +=
