#include "BinaryStepActivationFunction.hpp"

constexpr qreal EPS = 1e-5;

qreal BinaryStepActivationFunction::compute(qreal arg) const
{
    if (arg < EPS)
        return 0;
    else
        return 1;
}

qreal BinaryStepActivationFunction::computeDerivative(qreal arg) const
{
    return 1;
}
