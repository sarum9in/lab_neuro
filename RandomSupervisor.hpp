#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

#include <utility>

class NEUROSHARED_EXPORT RandomSupervisor: public Supervisor
{
public:
    using Supervisor::Supervisor;

    template <typename ... Args>
    explicit RandomSupervisor(const qreal minWeight, const qreal maxWeight, Args &&...args):
        Supervisor(std::forward<Args>(args)...)
    {
        setRandRange(minWeight, maxWeight);
    }

    bool train(NeuralNetwork &neuralNetwork) override;

    qreal minWeight() const;
    qreal maxWeight() const;
    void setRandRange(const qreal minWeight, const qreal maxWeight);

private:
    qreal m_minWeight = -1, m_maxWeight = 1;
};
