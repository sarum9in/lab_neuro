#ifndef NEURONET_HPP
#define NEURONET_HPP

#include "neuro_global.hpp"

#include "NeuroLayer.hpp"

#include <QVector>

class NEUROSHARED_EXPORT NeuroNet
{
public:
    NeuroNet();

    bool empty() const;
    int layerNumber() const;
    NeuroLayer &layer(const int index);
    const NeuroLayer &layer(const int index) const;
    NeuroLayer &firstLayer();
    const NeuroLayer &firstLayer() const;
    NeuroLayer &lastLayer();
    const NeuroLayer &lastLayer() const;

    int inputNumber() const;
    int outputNumber() const;

private:
    QVector<NeuroLayer> m_layers;
};

#endif // NEURONET_HPP
