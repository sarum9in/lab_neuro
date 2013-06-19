#include "RandomSupervisor.hpp"

#include <QDebug>

namespace {
qreal randReal(const qreal min, const qreal max)
{
    Q_ASSERT(min <= max);
    const qreal d = max - min;
    Q_ASSERT(d >= 0);
    const qreal rnd = static_cast<qreal>(qrand()) / RAND_MAX;
    const qreal r = d * rnd + min;
    if (r < min)
        return min;
    if (r > max)
        return max;
    return r;
}
}

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
