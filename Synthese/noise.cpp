#include "noise.h"
#include <cmath>
#include "mathutils.h"
#define M_PI 3.14159265358979323846
#include "smoothnoise.h"

Noise::Noise(int s):seed(s)
{
}


float Noise::pointToValue(QVector2D &p)
{
    return smooth_noiseABS(p,seed);
}

QVector2D Noise::pointToPoint(QVector2D &p)
{
    float rayon = pointToValue(p);
    float angle = pointToValue(p)*2*M_PI;
    QVector2D v(cos(angle)*rayon, sin(angle)*rayon);
    return v;
}


