#include "LogSigmoidActivationFunction.hpp"

#include <QtCore/qmath.h>

LogSigmoidActivationFunction::LogSigmoidActivationFunction(const qreal alpha):
    m_alpha(alpha) {}

qreal LogSigmoidActivationFunction::compute(qreal arg) const
{
    return 1 / (1 + qExp(-m_alpha * arg));
}

qreal LogSigmoidActivationFunction::computeDerivative(qreal arg) const
{
    const qreal f = compute(arg);
    return m_alpha * f * (1 - f);
}
