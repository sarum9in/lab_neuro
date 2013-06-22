#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

class NEUROSHARED_EXPORT StochasticSupervisor: public Supervisor
{
public:
    using Supervisor::Supervisor;

    bool trainFor(NeuralNetwork &neuralNetwork, const int count) override;
};
