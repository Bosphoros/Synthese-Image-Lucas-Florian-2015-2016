#include "noise.h"
#include <cmath>
#include "mathutils.h"
#define M_PI 3.14159265358979323846
#include "smoothnoise.h"

Noise::Noise(int s):seed(s)
{
}


double Noise::pointToValue(Vector2D &p)
{
    return raw_noise_2d(p.x(),p.y());
}

Vector2D Noise::pointToPoint(Vector2D &p)
{
    double rayon = pointToValue(p);
    double angle = pointToValue(p)*2*M_PI;
    Vector2D v(cos(angle)*rayon, sin(angle)*rayon);
    return v;
}


