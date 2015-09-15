#ifndef TERRAINNOISE_H
#define TERRAINNOISE_H
#include "terrain.h"
class TerrainNoise: public Terrain
{
public:
    TerrainNoise(const Vector2D &aa, const Vector2D &bb);
    virtual double getHauteur(const Vector2D& p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

#endif // TERRAINNOISE_H
