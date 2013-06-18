#include "TanSigmoidActivationFunction.hpp"

#include <QtCore/qmath.h>

qreal TanSigmoidActivationFunction::compute(qreal arg) const
{
    const qreal a = qExp(arg);
    const qreal b = qExp(-arg);
    return (a - b) / (a + b);
}
