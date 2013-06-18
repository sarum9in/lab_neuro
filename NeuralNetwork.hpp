#ifndef NEURONET_HPP
#define NEURONET_HPP

#include "neuro_global.hpp"

#include "NeuralLayer.hpp"

#include <QVector>

class NEUROSHARED_EXPORT NeuralNetwork
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

    int inputNumber() const;
    int outputNumber() const;

private:
    QVector<NeuralLayer> m_layers;
};

#endif // NEURONET_HPP
