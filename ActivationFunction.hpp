#pragma once

#include "neuro_global.hpp"

#include <QSharedPointer>

class NEUROSHARED_EXPORT ActivationFunction
{
public:
    virtual ~ActivationFunction();

    /// \note Function is reentrant
    virtual qreal compute(qreal arg) const=0;

    /// \note Function is reentrant
    virtual qreal computeDerivative(qreal arg) const=0;
};

typedef QSharedPointer<ActivationFunction> ActivationFunctionPointer;
