#pragma once

#include "neuro_global.hpp"

#include "ActivationFunction.hpp"

class NEUROSHARED_EXPORT TanSigmoidActivationFunction: public ActivationFunction
{
public:
    TanSigmoidActivationFunction()=default;

    qreal compute(qreal arg) const override;

    qreal computeDerivative(qreal arg) const override;
};
