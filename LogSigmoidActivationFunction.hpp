#pragma once

#include "neuro_global.hpp"

#include "ActivationFunction.hpp"

class NEUROSHARED_EXPORT LogSigmoidActivationFunction: public ActivationFunction
{
public:
    explicit LogSigmoidActivationFunction(const qreal alpha);

    qreal compute(qreal arg) const override;

private:
    const qreal m_alpha;
};
