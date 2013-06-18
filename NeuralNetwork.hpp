#pragma once

#include "neuro_global.hpp"

#include "DataTransformation.hpp"
#include "NeuralLayer.hpp"

#include <QMetaType>
#include <QVector>

class NEUROSHARED_EXPORT NeuralNetwork: public DataTransformation
{
public:
    NeuralNetwork()=default;

    NeuralNetwork(const NeuralNetwork &)=default;
    NeuralNetwork(NeuralNetwork &&)=default;
    NeuralNetwork &operator=(const NeuralNetwork &)=default;
    NeuralNetwork &operator=(NeuralNetwork &&)=default;

    bool empty() const;
    int layerNumber() const;
    NeuralLayer &layer(const int index);
    const NeuralLayer &layer(const int index) const;
    NeuralLayer &inputLayer();
    const NeuralLayer &inputLayer() const;
    NeuralLayer &outputLayer();
    const NeuralLayer &outputLayer() const;
    void pushFront(const NeuralLayer &layer);
    void pushBack(const NeuralLayer &layer);
    void popFront();
    void popBack();

    void setActivationFunction(const ActivationFunctionPointer &activationFunction);

    int inputNumber() const override;
    int outputNumber() const override;

protected:
    DataVector transform_(const DataVector &input) const override;

private:
    QVector<NeuralLayer> m_layers;
};

Q_DECLARE_METATYPE(NeuralNetwork)
