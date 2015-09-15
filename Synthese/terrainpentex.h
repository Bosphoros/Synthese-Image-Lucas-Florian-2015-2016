#ifndef TERRAINPENTEX_H
#define TERRAINPENTEX_H
#include "terrain.h"
#include "vector2d.h"

class TerrainPenteX:public Terrain
{
public:
    TerrainPenteX(Vector2D& a, Vector2D& b);
    virtual double getHauteur(const Vector2D &p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

#endif // TERRAINPENTEX_H
