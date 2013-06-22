#include "StochasticSupervisor.hpp"

#include "Random.hpp"
#include "RandomSupervisor.hpp"

#include <QDebug>

namespace
{
    qreal getError(const NeuralNetwork &neuralNetwork, const TrainingExample &example)
    {
        qreal e = 0;
        const DataVector output = neuralNetwork.transform(example.input);
        Q_ASSERT(output.size() == example.output.size());
        for (int i = 0; i < output.size(); ++i)
        {
            const qreal d = example.output[i] - output[i];
            e += 0.5 * d * d;
        }
        return e;
    }

    qreal getError(const NeuralNetwork &neuralNetwork, const TrainingVector &set)
    {
        qreal e = 0;
        for (const TrainingExample &example: set)
            e += getError(neuralNetwork, example);
        return e;
    }
}

constexpr qreal EPS = 0.1;
constexpr qreal MAX_TEMPERATURE = 1000;

bool StochasticSupervisor::trainFor(NeuralNetwork &neuralNetwork, const int count) const
{
    emit started(count);
    qreal bestError = 1e100;
    NeuralNetwork networkBackup;
    RandomSupervisor rnd(-5, 5);
    rnd.train(neuralNetwork);
    NeuralNetwork bestNetwork = neuralNetwork;
    for(int e = 1; e < count; ++e)
    {
        const qreal temperature = MAX_TEMPERATURE / (1 + e);
        const qreal temperature2 = temperature * temperature;
        const qreal oldError = getError(neuralNetwork, trainingSet());
        networkBackup = neuralNetwork;
        for (NeuralLayer &layer: neuralNetwork)
            for (Neuron &neuron: layer)
                for (int i = 0; i < neuron.weightNumber(); ++i)
                    neuron.setWeight(i, neuron.weight(i) + randReal(-0.25, 0.25));
        const qreal error = getError(neuralNetwork, trainingSet());
        { // info
            if (e % 100 == 0)
            {
                qDebug() << 100. * e / count << error << bestError; // FIXME DEBUG
                emit iterationInfo(e, count);
                emit targetErrorInfo(EPS, error, bestError);
            }
        }
        if (error > oldError)
        {
            const qreal errorDiff = error - oldError;
            const qreal errorDiff2 = errorDiff * errorDiff;
            const qreal P = temperature2 / (temperature2 + errorDiff2);
            const qreal random = randReal(0, 1);
            if (random > P)
                neuralNetwork.swap(networkBackup);
        }
        else
        {
            if (error < bestError)
            {
                bestNetwork = neuralNetwork;
                bestError = error;
            }
        }
        if (error < EPS)
        {
            emit finished(true);
            return true;
        }
    }
    neuralNetwork.swap(bestNetwork);
    emit finished(false);
    return false;
}
