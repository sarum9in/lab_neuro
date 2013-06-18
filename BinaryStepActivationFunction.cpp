#include "BinaryStepActivationFunction.hpp"

qreal BinaryStepActivationFunction::compute(qreal arg) const
{
    if (arg < 0)
        return 0;
    else
        return 1;
}

qreal BinaryStepActivationFunction::computeDerivative(qreal arg) const
{
    return 1;
}
