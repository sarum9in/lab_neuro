#pragma once

#include "neuro_global.hpp"

#include "ActivationFunction.hpp"

class NEUROSHARED_EXPORT BipolarStepActivationFunction: public ActivationFunction
{
public:
    BipolarStepActivationFunction();

    qreal compute(qreal arg) const override;
};
