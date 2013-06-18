#ifndef NEUROLAYER_HPP
#define NEUROLAYER_HPP

#include "neuro_global.hpp"

class NEUROSHARED_EXPORT NeuroLayer
{
public:
    NeuroLayer();

    int inputNumber() const;
    int outputNumber() const;
};

#endif // NEUROLAYER_HPP
