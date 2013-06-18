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
