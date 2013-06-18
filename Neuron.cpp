#include "Neuron.hpp"

#include <QDebug>

Neuron::Neuron(): m_weights(1) {}

Neuron::Neuron(const ActivationFunctionPointer &activationFunction):
    m_activationFunction(activationFunction),
    m_weights(1) {}

Neuron::Neuron(const ActivationFunctionPointer &activationFunction, const WeightVector &weights):
    m_activationFunction(activationFunction),
    m_weights(weights)
{
    Q_ASSERT(!weights.empty());
}

bool Neuron::hasActivationFunction() const
{
    return !m_activationFunction.isNull();
}

const ActivationFunctionPointer &Neuron::activationFunction() const
{
    return m_activationFunction;
}

void Neuron::setActivationFunction(const ActivationFunctionPointer &activationFunction)
{
    m_activationFunction = activationFunction;
}

WeightVector &Neuron::weights()
{
    return m_weights;
}

const WeightVector &Neuron::weights() const
{
    return m_weights;
}

void Neuron::setWeights(const WeightVector &weights)
{
    Q_ASSERT(!weights.empty());
    m_weights = weights;
}

int Neuron::weightNumber() const
{
    return m_weights.size();
}

qreal Neuron::weight(const int index) const
{
    Q_ASSERT(0 <= index && index < weightNumber());
    return m_weights[index];
}

void Neuron::setWeight(const int index, const qreal weight)
{
    Q_ASSERT(0 <= index && index < weightNumber());
    m_weights[index] = weight;
}

qreal Neuron::bias() const
{
    return weight(0);
}

void Neuron::setBias(const qreal bias)
{
    setWeight(0, bias);
}

int Neuron::inputNumber() const
{
    return m_weights.size() - 1;
}

int Neuron::outputNumber() const
{
    return 1;
}
