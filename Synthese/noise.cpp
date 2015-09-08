#include "noise.h"

Noise::Noise(quint16 f, quint16 a):freq(f), ampli(a)
{
}

float noise(float v) {
    return (sin(v)*78523.4564659)%1;
}

float Noise::pointToValue(QVector2D &p)
{
    return noise(noise(p.x()) * 984617 + p.y());
}
