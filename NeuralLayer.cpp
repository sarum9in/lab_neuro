#include "NeuralLayer.hpp"

#include <QDebug>

NeuralLayer::NeuralLayer()
{
}

bool NeuralLayer::empty() const
{
    return m_neurons.empty();
}

int NeuralLayer::neuronNumber() const
{
    return m_neurons.size();
}

Neuron &NeuralLayer::neuron(const int index)
{
    Q_ASSERT(0 <= index && index < neuronNumber());
    return m_neurons[index];
}

const Neuron &NeuralLayer::neuron(const int index) const
{
    Q_ASSERT(0 <= index && index < neuronNumber());
    return m_neurons[index];
}

int NeuralLayer::inputNumber() const
{
    if (empty())
        return 0;
    else
        return neuron(0).inputNumber(); // equal among neurons
}

int NeuralLayer::outputNumber() const
{
    return neuronNumber();
}
