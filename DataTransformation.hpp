#pragma once

#include "neuro_global.hpp"

#include <QVector>

typedef QVector<qreal> DataVector;

class NEUROSHARED_EXPORT DataTransformation
{
public:
    virtual ~DataTransformation();

    DataVector transform(const DataVector &input) const;

    virtual int inputNumber() const=0;
    virtual int outputNumber() const=0;

protected:
    void checkInput(const DataVector &input) const;
    void checkOutput(const DataVector &output) const;

    virtual DataVector transform_(const DataVector &input) const=0;
};
