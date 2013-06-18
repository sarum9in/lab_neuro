#include "LogSigmoidActivationFunction.hpp"

#include <QtCore/qmath.h>

LogSigmoidActivationFunction::LogSigmoidActivationFunction(const qreal alpha):
    m_alpha(alpha) {}

qreal LogSigmoidActivationFunction::compute(qreal arg) const
{
    return 1 / (1 + qExp(-m_alpha * arg));
}
