#include "DataTransformation.hpp"

#include <QDebug>

DataTransformation::~DataTransformation() {}

void DataTransformation::checkInput(const DataVector &input) const
{
    Q_ASSERT(input.size() == inputNumber());
}

void DataTransformation::checkOutput(const DataVector &output) const
{
    Q_ASSERT(output.size() == outputNumber());
}

DataVector DataTransformation::transform(const DataVector &input) const
{
    checkInput(input);
    DataVector output = transform_(input);
    checkOutput(output);
    return output;
}
