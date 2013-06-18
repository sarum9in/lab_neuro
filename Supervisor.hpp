#pragma once

#include "neuro_global.hpp"

#include "DataTransformation.hpp"
#include "NeuralNetwork.hpp"

#include <QObject>

struct TrainingExample
{
    DataVector input, output;
};

typedef QVector<TrainingExample> TrainingVector;

class NEUROSHARED_EXPORT Supervisor: public QObject
{
    Q_OBJECT

public:
    explicit Supervisor(QObject *parent=nullptr);
    explicit Supervisor(const TrainingVector &trainingSet, QObject *parent=nullptr);

    const TrainingVector &trainingSet() const;
    void setTrainingSet(const TrainingVector &trainingSet);

    qreal learningSpeed() const;
    void setLearningSpeed(const qreal learningSpeed);

    virtual void train(NeuralNetwork &neuralNetwork) const=0;

private:
    TrainingVector m_trainingSet;
    qreal m_learningSpeed = 1;
};
