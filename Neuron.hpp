#pragma once

#include "neuro_global.hpp"

#include "ActivationFunction.hpp"
#include "DataTransformation.hpp"

#include <QMetaType>
#include <QVector>

typedef QVector<qreal> WeightVector;

class NEUROSHARED_EXPORT Neuron: public DataTransformation
{
public:
    Neuron();
    explicit Neuron(const ActivationFunctionPointer &activationFunction);
    Neuron(const ActivationFunctionPointer &activationFunction, const WeightVector &weights);

    Neuron(const Neuron &)=default;
    Neuron(Neuron &&)=default;
    Neuron &operator=(const Neuron &)=default;
    Neuron &operator=(Neuron &&)=default;

    void swap(Neuron &neuron) noexcept;

    /// Check if ActivationFunction is initialized.
    bool hasActivationFunction() const;
    const ActivationFunctionPointer &activationFunction() const;
    void setActivationFunction(const ActivationFunctionPointer &activationFunction);

    /// \note: 0th element is bias
    WeightVector &weights();
    /// \copydoc weights()
    const WeightVector &weights() const;
    void setWeights(const WeightVector &weights);
    void clear();

    int weightNumber() const;
    qreal weight(const int index) const;
    void setWeight(const int index, const qreal weight);
    qreal bias() const;
    void setBias(const qreal bias);

    qreal compute(const DataVector &input, qreal *weightedSum=nullptr) const;

    int inputNumber() const override;
    int outputNumber() const override;

protected:
    DataVector transform_(const DataVector &input) const override;

private:
    ActivationFunctionPointer m_activationFunction;
    WeightVector m_weights;
};

Q_DECLARE_METATYPE(Neuron)
