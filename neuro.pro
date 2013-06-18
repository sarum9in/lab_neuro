#-------------------------------------------------
#
# Project created by QtCreator 2013-06-18T17:13:05
#
#-------------------------------------------------

QT       -= gui

TARGET = neuro
TEMPLATE = lib

DEFINES += NEURO_LIBRARY

SOURCES += Neuron.cpp \
    NeuroNet.cpp \
    NeuroLayer.cpp \
    ActivationFunction.cpp

HEADERS += Neuron.hpp\
        neuro_global.hpp \
    NeuroNet.hpp \
    NeuroLayer.hpp \
    ActivationFunction.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
