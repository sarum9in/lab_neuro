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
    ActivationFunction.cpp \
    NeuralLayer.cpp \
    NeuralNetwork.cpp

HEADERS += Neuron.hpp\
        neuro_global.hpp \
    ActivationFunction.hpp \
    NeuralLayer.hpp \
    NeuralNetwork.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
