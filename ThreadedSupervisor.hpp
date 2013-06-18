#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

#include <QObject>
#include <QThread>

namespace detail
{
class NEUROSHARED_EXPORT ThreadedSupervisorWorker: public QObject
{
    Q_OBJECT

public:
    explicit ThreadedSupervisorWorker(Supervisor *supervisor, QObject *parent=nullptr);

signals:
    void resultReady(const NeuralNetwork &neuralNetwork);

public slots:
    void doWork(NeuralNetwork neuralNetwork);

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
    void start(const NeuralNetwork &NeuralNetwork);
    void started();
    void finished(const NeuralNetwork &neuralNetwork);

public slots:
    void train(const NeuralNetwork &neuralNetwork);

private:
    QThread m_workerThread;
};
