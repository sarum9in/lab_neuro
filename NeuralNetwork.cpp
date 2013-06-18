#include "NeuralNetwork.hpp"

#include <QDebug>

NeuralNetwork::NeuralNetwork()
{
}

bool NeuralNetwork::empty() const
{
    return m_layers.empty();
}

int NeuralNetwork::layerNumber() const
{
    return m_layers.size();
}

NeuralLayer &NeuralNetwork::layer(const int index)
{
    Q_ASSERT(0 <= index && index < layerNumber());
    return m_layers[index];
}

const NeuralLayer &NeuralNetwork::layer(const int index) const
{
    Q_ASSERT(0 <= index && index < layerNumber());
    return m_layers[index];
}

NeuralLayer &NeuralNetwork::firstLayer()
{
    Q_ASSERT(!empty());
    return m_layers.first();
}

const NeuralLayer &NeuralNetwork::firstLayer() const
{
    Q_ASSERT(!empty());
    return m_layers.first();
}

NeuralLayer &NeuralNetwork::lastLayer()
{
    Q_ASSERT(!empty());
    return m_layers.last();
}

const NeuralLayer &NeuralNetwork::lastLayer() const
{
    Q_ASSERT(!empty());
    return m_layers.last();
}

int NeuralNetwork::inputNumber() const
{
    return firstLayer().inputNumber();
}

int NeuralNetwork::outputNumber() const
{
    return lastLayer().outputNumber();
}
