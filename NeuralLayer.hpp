#pragma once

#include "neuro_global.hpp"

#include "DataTransformation.hpp"
#include "Neuron.hpp"

#include <QVector>

class NEUROSHARED_EXPORT NeuralLayer: public DataTransformation
{
public:
    NeuralLayer();

    bool empty() const;
    int neuronNumber() const;
    Neuron &neuron(const int index);
    const Neuron &neuron(const int index) const;

    int inputNumber() const override;
    int outputNumber() const override;

protected:
    DataVector transform_(const DataVector &input) const override;

private:
    QVector<Neuron> m_neurons;
};
