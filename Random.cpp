#include "Random.hpp"

qreal NEUROSHARED_EXPORT randReal(const qreal min, const qreal max)
{
    Q_ASSERT(min <= max);
    const qreal d = max - min;
    Q_ASSERT(d >= 0);
    const qreal rnd = static_cast<qreal>(qrand()) / RAND_MAX;
    const qreal r = d * rnd + min;
    if (r < min)
        return min;
    if (r > max)
        return max;
    return r;
}
