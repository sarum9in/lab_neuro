#include "BipolarStepActivationFunction.hpp"

qreal BipolarStepActivationFunction::compute(qreal arg) const
{
    if (arg < 0)
        return -1;
    else
        return 1;
}

qreal BipolarStepActivationFunction::computeDerivative(qreal arg) const
{
    return 1;
}
