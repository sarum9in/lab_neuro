#ifndef NEUROLAYER_HPP
#define NEUROLAYER_HPP

#include "neuro_global.hpp"

#include "Neuron.hpp"

#include <QVector>

class NEUROSHARED_EXPORT NeuralLayer
{
public:
    NeuralLayer();

    bool empty() const;
    int neuronNumber() const;
    Neuron &neuron(const int index);
    const Neuron &neuron(const int index) const;

    int inputNumber() const;
    int outputNumber() const;

private:
    QVector<Neuron> m_neurons;
};

#endif // NEUROLAYER_HPP
