#include "BackpropagationSupervisor.hpp"

qreal BackpropagationSupervisor::learningSpeed() const
{
    return m_learningSpeed;
}

void BackpropagationSupervisor::setLearningSpeed(const qreal learningSpeed)
{
    m_learningSpeed = learningSpeed;
}

void BackpropagationSupervisor::train(NeuralNetwork &neuralNetwork) const
{
    // TODO
}
