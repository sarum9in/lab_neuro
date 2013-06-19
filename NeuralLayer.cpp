#include "NeuralLayer.hpp"

#include <QDebug>

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

void NeuralLayer::pushFront(const Neuron &neuron)
{
    Q_ASSERT(empty() || inputNumber() == neuron.inputNumber());
    m_neurons.push_front(neuron);
}

void NeuralLayer::pushBack(const Neuron &neuron)
{
    Q_ASSERT(empty() || inputNumber() == neuron.inputNumber());
    m_neurons.push_front(neuron);
}

void NeuralLayer::popFront()
{
    m_neurons.pop_front();
}

void NeuralLayer::popBack()
{
    m_neurons.pop_back();
}

void NeuralLayer::clear()
{
    m_neurons.clear();
}

void NeuralLayer::setActivationFunction(const ActivationFunctionPointer &activationFunction)
{
    for (Neuron &neuron: m_neurons)
        neuron.setActivationFunction(activationFunction);
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

DataVector NeuralLayer::transform_(const DataVector &input) const
{
    DataVector output(outputNumber());
    for (int i = 0; i < neuronNumber(); ++i)
        output[i] = m_neurons[i].compute(input);
    return output;
}
