#ifndef SMOOTHNOISE_H
#define SMOOTHNOISE_H
#include "vector2d.h"

double smooth_noise(Vector2D p, int seed);
double smooth_noiseBilinear(Vector2D p, int seed);


#endif // SMOOTHNOISE_H
