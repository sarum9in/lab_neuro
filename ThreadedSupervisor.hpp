#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

#include <QObject>
#include <QThread>

namespace detail {
class NEUROSHARED_EXPORT ThreadedSupervisorWorker: public QObject
{
    Q_OBJECT

public:
    explicit ThreadedSupervisorWorker(Supervisor *supervisor, QObject *parent=nullptr);

signals:
    void resultReady(const bool result, const NeuralNetwork &neuralNetwork);

public slots:
    void doWork(NeuralNetwork neuralNetwork, const int count);

private:
    Supervisor *const m_supervisor;
};
} // detail

class NEUROSHARED_EXPORT ThreadedSupervisor: public QObject
{
    Q_OBJECT

public:
    /// \param supervisor transfers ownership
    explicit ThreadedSupervisor(Supervisor *supervisor, QObject *parent=nullptr);
    ~ThreadedSupervisor();

signals:
    void start(const NeuralNetwork &NeuralNetwork, const int count);
    void resultReady(const bool result, const NeuralNetwork &neuralNetwork);

    void started(const int count) const;
    void finished(const bool result) const;
    void targetErrorInfo(const qreal targetError, const qreal currentError, const qreal bestError) const;
    void iterationInfo(const int currentIteration, const int maxIterations) const;

    void abortSent();
    void trainingSetUpdated(const TrainingVector &trainingSet);

public slots:
    void trainFor(const NeuralNetwork &neuralNetwork, const int count);
    void abort();
    void setTrainingSet(const TrainingVector &trainingSet);

private:
    QThread m_workerThread;
};
