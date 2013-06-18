#pragma once

#include "neuro_global.hpp"

#include "DataTransformation.hpp"
#include "NeuralLayer.hpp"

#include <QVector>

class NEUROSHARED_EXPORT NeuralNetwork: public DataTransformation
{
public:
    NeuralNetwork();

    bool empty() const;
    int layerNumber() const;
    NeuralLayer &layer(const int index);
    const NeuralLayer &layer(const int index) const;
    NeuralLayer &inputLayer();
    const NeuralLayer &inputLayer() const;
    NeuralLayer &outputLayer();
    const NeuralLayer &outputLayer() const;

    int inputNumber() const override;
    int outputNumber() const override;

protected:
    DataVector transform_(const DataVector &data) const override;

private:
    QVector<NeuralLayer> m_layers;
};
