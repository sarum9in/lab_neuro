#include "DeltaRuleSupervisor.hpp"

constexpr qreal EPS = 0.01;

bool DeltaRuleSupervisor::train(NeuralNetwork &neuralNetwork)
{
    Q_ASSERT(neuralNetwork.layerNumber() == 1);
    NeuralLayer &layer = neuralNetwork.layer(0);
    for (const TrainingExample &example: trainingSet())
    {
        Q_ASSERT(layer.inputNumber() == example.input.size());
        DataVector output(layer.neuronNumber());
        DataVector weightedSum(layer.neuronNumber());
        for (int i = 0; i < layer.neuronNumber(); ++i)
            output[i] = layer.neuron(i).compute(example.input, &weightedSum[i]);
        Q_ASSERT(output.size() == example.output.size());
        for (int i = 0; i < output.size(); ++i)
        {
            Neuron &neuron = layer.neuron(i);
            const qreal delta = learningSpeed() * (example.output[i] - output[i]) *
                                neuron.activationFunction()->computeDerivative(weightedSum[i]);
            neuron.setBias(neuron.bias() + delta);
            for (int j = 0; j < neuron.inputNumber(); ++j)
                neuron.setWeight(j + 1, neuron.weight(j + 1) + example.input[j] * delta);
        }
    }
    qreal error = 0;
    for (const TrainingExample &example: trainingSet())
    {
        DataVector output = layer.transform(example.input);
        for (int i = 0; i < output.size(); ++i)
            error += qAbs(output[i] - example.output[i]);
    }
    return error < EPS;
}
