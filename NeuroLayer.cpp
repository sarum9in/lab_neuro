#include "NeuroLayer.hpp"

#include <QDebug>

NeuroLayer::NeuroLayer()
{
}

bool NeuroLayer::empty() const
{
    return m_neurons.empty();
}

int NeuroLayer::neuronNumber() const
{
    return m_neurons.size();
}

Neuron &NeuroLayer::neuron(const int index)
{
    Q_ASSERT(0 <= index && index < neuronNumber());
    return m_neurons[index];
}

const Neuron &NeuroLayer::neuron(const int index) const
{
    Q_ASSERT(0 <= index && index < neuronNumber());
    return m_neurons[index];
}

int NeuroLayer::inputNumber() const
{
    if (empty())
        return 0;
    else
        return neuron(0).inputNumber(); // equal among neurons
}

int NeuroLayer::outputNumber() const
{
    return neuronNumber();
}
