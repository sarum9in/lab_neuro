#include "ThreadedSupervisor.hpp"

namespace detail {
ThreadedSupervisorWorker::ThreadedSupervisorWorker(Supervisor *supervisor, QObject *parent):
    QObject(parent),
    m_supervisor(supervisor)
{
    Q_ASSERT(m_supervisor);
    m_supervisor->setParent(this);
}

void ThreadedSupervisorWorker::doWork(NeuralNetwork neuralNetwork)
{
    m_supervisor->train(neuralNetwork);
    emit resultReady(neuralNetwork);
}
} // detail

ThreadedSupervisor::ThreadedSupervisor(Supervisor *supervisor, QObject *parent):
    QObject(parent)
{
    detail::ThreadedSupervisorWorker *worker = new detail::ThreadedSupervisorWorker(supervisor);
    worker->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &ThreadedSupervisor::start, worker, &detail::ThreadedSupervisorWorker::doWork);
    connect(worker, &detail::ThreadedSupervisorWorker::resultReady, this, &ThreadedSupervisor::finished);
    m_workerThread.start();
}

ThreadedSupervisor::~ThreadedSupervisor()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void ThreadedSupervisor::train(const NeuralNetwork &neuralNetwork)
{
    emit start(neuralNetwork);
}
