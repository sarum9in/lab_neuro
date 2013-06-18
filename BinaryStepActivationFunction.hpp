#pragma once

#include "neuro_global.hpp"

#include "ActivationFunction.hpp"

class NEUROSHARED_EXPORT BinaryStepActivationFunction: public ActivationFunction
{
public:
    BinaryStepActivationFunction()=default;

    qreal compute(qreal arg) const override;
};
