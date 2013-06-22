#include "ThreadedSupervisor.hpp"

namespace detail {
ThreadedSupervisorWorker::ThreadedSupervisorWorker(Supervisor *supervisor, QObject *parent):
    QObject(parent),
    m_supervisor(supervisor)
{
    Q_ASSERT(m_supervisor);
    m_supervisor->setParent(this);
}

void ThreadedSupervisorWorker::doWork(NeuralNetwork neuralNetwork, const int count)
{
    const bool result = m_supervisor->trainFor(neuralNetwork, count);
    emit resultReady(result, neuralNetwork);
}
} // detail

ThreadedSupervisor::ThreadedSupervisor(Supervisor *supervisor, QObject *parent):
    QObject(parent)
{
    detail::ThreadedSupervisorWorker *worker = new detail::ThreadedSupervisorWorker(supervisor);
    worker->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &ThreadedSupervisor::start, worker, &detail::ThreadedSupervisorWorker::doWork);
    connect(worker, &detail::ThreadedSupervisorWorker::resultReady, this, &ThreadedSupervisor::resultReady);
    connect(this, &ThreadedSupervisor::abortSent, supervisor, &Supervisor::abort);
    connect(this, &ThreadedSupervisor::trainingSetUpdated, supervisor, &Supervisor::setTrainingSet);
    connect(supervisor, &Supervisor::started, this, &ThreadedSupervisor::started);
    connect(supervisor, &Supervisor::finished, this, &ThreadedSupervisor::finished);
    connect(supervisor, &Supervisor::targetErrorInfo, this, &ThreadedSupervisor::targetErrorInfo);
    connect(supervisor, &Supervisor::iterationInfo, this, &ThreadedSupervisor::iterationInfo);
    m_workerThread.start();
}

ThreadedSupervisor::~ThreadedSupervisor()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void ThreadedSupervisor::trainFor(const NeuralNetwork &neuralNetwork, const int count)
{
    emit start(neuralNetwork, count);
}

void ThreadedSupervisor::abort()
{
    emit abortSent();
}

void ThreadedSupervisor::setTrainingSet(const TrainingVector &trainingSet)
{
    emit trainingSetUpdated(trainingSet);
}
