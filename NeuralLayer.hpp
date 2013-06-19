#pragma once

#include "neuro_global.hpp"

#include "DataTransformation.hpp"
#include "Neuron.hpp"

#include <QMetaType>
#include <QVector>

class NEUROSHARED_EXPORT NeuralLayer: public DataTransformation
{
public:
    NeuralLayer()=default;

    NeuralLayer(const NeuralLayer &)=default;
    NeuralLayer(NeuralLayer &&)=default;
    NeuralLayer &operator=(const NeuralLayer &)=default;
    NeuralLayer &operator=(NeuralLayer &&)=default;

    bool empty() const;
    int neuronNumber() const;
    Neuron &neuron(const int index);
    const Neuron &neuron(const int index) const;
    void pushFront(const Neuron &neuron);
    void pushBack(const Neuron &neuron);
    void popFront();
    void popBack();

    void setActivationFunction(const ActivationFunctionPointer &activationFunction);

    int inputNumber() const override;
    int outputNumber() const override;

protected:
    DataVector transform_(const DataVector &input) const override;

private:
    inline friend QVector<Neuron>::iterator begin(NeuralLayer &neuralLayer)
    {
        return neuralLayer.m_neurons.begin();
    }

    inline friend QVector<Neuron>::const_iterator begin(const NeuralLayer &neuralLayer)
    {
        return neuralLayer.m_neurons.begin();
    }

    inline friend QVector<Neuron>::iterator end(NeuralLayer &neuralLayer)
    {
        return neuralLayer.m_neurons.end();
    }

    inline friend QVector<Neuron>::const_iterator end(const NeuralLayer &neuralLayer)
    {
        return neuralLayer.m_neurons.end();
    }

private:
    QVector<Neuron> m_neurons;
};

Q_DECLARE_METATYPE(NeuralLayer)
