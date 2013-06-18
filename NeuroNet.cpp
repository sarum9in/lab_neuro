#include "NeuroNet.hpp"

#include <QDebug>

NeuroNet::NeuroNet()
{
}

bool NeuroNet::empty() const
{
    return m_layers.empty();
}

int NeuroNet::layerNumber() const
{
    return m_layers.size();
}

NeuroLayer &NeuroNet::layer(const int index)
{
    Q_ASSERT(0 <= index && index < layerNumber());
    return m_layers[index];
}

const NeuroLayer &NeuroNet::layer(const int index) const
{
    Q_ASSERT(0 <= index && index < layerNumber());
    return m_layers[index];
}

NeuroLayer &NeuroNet::firstLayer()
{
    Q_ASSERT(!empty());
    return m_layers.first();
}

const NeuroLayer &NeuroNet::firstLayer() const
{
    Q_ASSERT(!empty());
    return m_layers.first();
}

NeuroLayer &NeuroNet::lastLayer()
{
    Q_ASSERT(!empty());
    return m_layers.last();
}

const NeuroLayer &NeuroNet::lastLayer() const
{
    Q_ASSERT(!empty());
    return m_layers.last();
}

int NeuroNet::inputNumber() const
{
    return firstLayer().inputNumber();
}

int NeuroNet::outputNumber() const
{
    return lastLayer().outputNumber();
}
