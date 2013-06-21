#include "RandomSupervisor.hpp"

#include "Random.hpp"

#include <QDebug>

bool RandomSupervisor::train(NeuralNetwork &neuralNetwork) const
{
    for (NeuralLayer &layer: neuralNetwork)
        for (Neuron &neuron: layer)
            for (int i = 0; i < neuron.weightNumber(); ++i)
                neuron.setWeight(i, randReal(m_minWeight, m_maxWeight));
    return true;
}

qreal RandomSupervisor::minWeight() const
{
    return m_minWeight;
}

qreal RandomSupervisor::maxWeight() const
{
    return m_maxWeight;
}

void RandomSupervisor::setRandRange(const qreal minWeight, const qreal maxWeight)
{
    Q_ASSERT(minWeight <= maxWeight);
    m_minWeight = minWeight;
    m_maxWeight = maxWeight;
}
