#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

class NEUROSHARED_EXPORT BackpropagationSupervisor: public Supervisor
{
public:
    using Supervisor::Supervisor;

    bool train(NeuralNetwork &neuralNetwork) override;
};
