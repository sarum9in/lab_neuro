#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

class NEUROSHARED_EXPORT DeltaRuleSupervisor: public Supervisor
{
public:
    using Supervisor::Supervisor;

    bool train(NeuralNetwork &neuralNetwork) override;
};
