#ifndef NOISE_H
#define NOISE_H
#include "vector2d.h"
class Noise
{
private:
    int seed;
public:
    Noise(int seed=0);
    double pointToValue(Vector2D& p);
    Vector2D pointToPoint(Vector2D& p);
};

#endif // NOISE_H
