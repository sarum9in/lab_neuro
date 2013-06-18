#ifndef NEURON_HPP
#define NEURON_HPP

#include "neuro_global.hpp"

#include "ActivationFunction.hpp"

#include <QVector>

typedef QVector<qreal> WeightVector;

class NEUROSHARED_EXPORT Neuron
{
public:
    Neuron();
    explicit Neuron(const ActivationFunctionPointer &activationFunction);
    Neuron(const ActivationFunctionPointer &activationFunction, const WeightVector &weights);

    /// Check if ActivationFunction is initialized.
    bool hasActivationFunction() const;
    const ActivationFunctionPointer &activationFunction() const;
    void setActivationFunction(const ActivationFunctionPointer &activationFunction);

    /// \note: 0th element is bias
    WeightVector &weights();
    /// \copydoc weights()
    const WeightVector &weights() const;
    void setWeights(const WeightVector &weights);

    int inputNumber() const;
    int outputNumber() const;

private:
    ActivationFunctionPointer m_activationFunction;
    WeightVector m_weights;
};

#endif // NEURON_HPP
