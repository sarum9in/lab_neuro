#-------------------------------------------------
#
# Project created by QtCreator 2013-06-18T17:13:05
#
#-------------------------------------------------

QT       -= gui

TARGET = neuro
TEMPLATE = lib

CONFIG += c++11

DEFINES += NEURO_LIBRARY

SOURCES += Neuron.cpp \
    ActivationFunction.cpp \
    NeuralLayer.cpp \
    NeuralNetwork.cpp \
    DataTransformation.cpp \
    BipolarStepActivationFunction.cpp \
    BinaryStepActivationFunction.cpp \
    LogSigmoidActivationFunction.cpp \
    TanSigmoidActivationFunction.cpp \
    Supervisor.cpp \
    ThreadedSupervisor.cpp \
    DeltaRuleSupervisor.cpp \
    BackpropagationSupervisor.cpp \
    GeneticSupervisor.cpp \
    RandomSupervisor.cpp \
    StochasticSupervisor.cpp \
    Random.cpp

HEADERS += Neuron.hpp\
        neuro_global.hpp \
    ActivationFunction.hpp \
    NeuralLayer.hpp \
    NeuralNetwork.hpp \
    DataTransformation.hpp \
    BipolarStepActivationFunction.hpp \
    BinaryStepActivationFunction.hpp \
    LogSigmoidActivationFunction.hpp \
    TanSigmoidActivationFunction.hpp \
    Supervisor.hpp \
    ThreadedSupervisor.hpp \
    DeltaRuleSupervisor.hpp \
    BackpropagationSupervisor.hpp \
    GeneticSupervisor.hpp \
    RandomSupervisor.hpp \
    StochasticSupervisor.hpp \
    Random.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
