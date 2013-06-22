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

    /*!
     * \return true if all training examples work correct
     *
     * \note Default implementation returns false.
     */
    virtual bool train(NeuralNetwork &neuralNetwork);

    /*!
     * \brief Train up to count times.
     *
     * \return last train() call (false if train() was not called)
     */
    virtual bool trainFor(NeuralNetwork &neuralNetwork, const int count);

public slots:
    void abort();

signals:
    void started(const int count);
    void finished(const bool result);
    void targetErrorInfo(const qreal targetError, const qreal currentError, const qreal bestError);
    void iterationInfo(const int currentIteration, const int maxIterations);

protected:
    bool checkAborted();

private:
    TrainingVector m_trainingSet;
    qreal m_learningSpeed = 1;
    bool m_aborted = false;
};
