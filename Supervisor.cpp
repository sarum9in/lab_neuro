#include "Supervisor.hpp"

Supervisor::Supervisor(QObject *parent):
    QObject(parent) {}

Supervisor::Supervisor(const TrainingVector &trainingSet, QObject *parent):
    QObject(parent),
    m_trainingSet(trainingSet) {}

const TrainingVector &Supervisor::trainingSet() const
{
    return m_trainingSet;
}

void Supervisor::setTrainingSet(const TrainingVector &trainingSet)
{
    m_trainingSet = trainingSet;
}

qreal Supervisor::learningSpeed() const
{
    return m_learningSpeed;
}

void Supervisor::setLearningSpeed(const qreal learningSpeed)
{
    m_learningSpeed = learningSpeed;
}

bool Supervisor::train(NeuralNetwork &neuralNetwork) const
{
    return false;
}

bool Supervisor::trainFor(NeuralNetwork &neuralNetwork, const int count) const
{
    for (int i = 0; i < count; ++i)
        if (train(neuralNetwork))
            return true;
    return false;
}
