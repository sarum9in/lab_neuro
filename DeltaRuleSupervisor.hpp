#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

#include <utility>

class NEUROSHARED_EXPORT DeltaRuleSupervisor: public Supervisor
{
public:
    template <typename ... Args>
    explicit DeltaRuleSupervisor(const qreal learningSpeed, Args &&...args):
        Supervisor(std::forward<Args>(args)...),
        m_learningSpeed(learningSpeed) {}

    qreal learningSpeed() const;
    void setLearningSpeed(const qreal learningSpeed);

    void train(NeuralNetwork &neuralNetwork) const override;

private:
      qreal m_learningSpeed;
};
