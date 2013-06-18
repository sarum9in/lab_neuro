#include "DataTransformation.hpp"

#include <QDebug>

DataTransformation::~DataTransformation() {}

DataVector DataTransformation::transform(const DataVector &data) const
{
    Q_ASSERT(data.size() == inputNumber());
    DataVector output = transform_(data);
    Q_ASSERT(output.size() == outputNumber());
    return output;
}
