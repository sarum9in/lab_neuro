#ifndef DATATRANSFORMATION_HPP
#define DATATRANSFORMATION_HPP

#include "neuro_global.hpp"

#include <QVector>

typedef QVector<qreal> DataVector;

class NEUROSHARED_EXPORT DataTransformation
{
public:
    virtual ~DataTransformation();

    DataVector transform(const DataVector &data) const;

    virtual int inputNumber() const=0;
    virtual int outputNumber() const=0;

protected:
    virtual DataVector transform_(const DataVector &data) const=0;
};

#endif // DATATRANSFORMATION_HPP
