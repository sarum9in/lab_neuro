#include "NeuralNetwork.hpp"

#include <QDebug>

void NeuralNetwork::swap(NeuralNetwork &neuralNetwork) noexcept
{
    m_layers.swap(neuralNetwork.m_layers);
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

NeuralLayer &NeuralNetwork::inputLayer()
{
    Q_ASSERT(!empty());
    return m_layers.first();
}

const NeuralLayer &NeuralNetwork::inputLayer() const
{
    Q_ASSERT(!empty());
    return m_layers.first();
}

NeuralLayer &NeuralNetwork::outputLayer()
{
    Q_ASSERT(!empty());
    return m_layers.last();
}

const NeuralLayer &NeuralNetwork::outputLayer() const
{
    Q_ASSERT(!empty());
    return m_layers.last();
}

void NeuralNetwork::pushFront(const NeuralLayer &layer)
{
    Q_ASSERT(empty() || inputNumber() == layer.outputNumber());
    m_layers.push_front(layer);
}

void NeuralNetwork::pushBack(const NeuralLayer &layer)
{
    Q_ASSERT(empty() || outputNumber() == layer.inputNumber());
    m_layers.push_back(layer);
}

void NeuralNetwork::popFront()
{
    m_layers.pop_front();
}

void NeuralNetwork::popBack()
{
    m_layers.pop_back();
}

void NeuralNetwork::clear()
{
    m_layers.clear();
}

void NeuralNetwork::setActivationFunction(const ActivationFunctionPointer &activationFunction)
{
    for (NeuralLayer &layer: m_layers)
        layer.setActivationFunction(activationFunction);
}

int NeuralNetwork::inputNumber() const
{
    return inputLayer().inputNumber();
}

int NeuralNetwork::outputNumber() const
{
    return outputLayer().outputNumber();
}

DataVector NeuralNetwork::transform_(const DataVector &input) const
{
    DataVector v = input;
    for (const NeuralLayer &layer: m_layers)
        v = layer.transform(v);
    return v;
}

static const int neuralNetworkId = qRegisterMetaType<NeuralNetwork>();
