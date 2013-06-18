#pragma once

#include "neuro_global.hpp"

#include "Supervisor.hpp"

class NEUROSHARED_EXPORT GeneticSupervisor: public Supervisor
{
public:
    using Supervisor::Supervisor;

    void train(NeuralNetwork &neuralNetwork) const override;
};
