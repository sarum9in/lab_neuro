#ifndef NEURON_HPP
#define NEURON_HPP

#include "neuro_global.hpp"

class NEUROSHARED_EXPORT Neuron
{
public:
    Neuron();

    int inputNumber() const;
    int outputNumber() const;
};

#endif // NEURON_HPP
