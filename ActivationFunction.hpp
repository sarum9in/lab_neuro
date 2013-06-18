#ifndef ACTIVATIONFUNCTION_HPP
#define ACTIVATIONFUNCTION_HPP

#include "neuro_global.hpp"

#include <QSharedPointer>

class NEUROSHARED_EXPORT ActivationFunction
{
public:
    virtual ~ActivationFunction();

    /// \note Function is reentrant
    virtual qreal compute(qreal arg) const=0;
};

typedef QSharedPointer<ActivationFunction> ActivationFunctionPointer;

#endif // ACTIVATIONFUNCTION_HPP
