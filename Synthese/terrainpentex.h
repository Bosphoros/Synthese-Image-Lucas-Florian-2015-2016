#ifndef TERRAINPENTEX_H
#define TERRAINPENTEX_H
#include "terrain.h"
#include "vector2d.h"

class TerrainPenteX:public Terrain
{
public:
    TerrainPenteX(Vector2D& a, Vector2D& b);
    virtual double getHauteur(const Vector2D &p);
    virtual double getHauteurMin(const Vector2D& aa, const Vector2D& bb);
    virtual double getHauteurMax(const Vector2D& aa, const Vector2D& bb);
    virtual double getPenteMax(const Vector2D& aa, const Vector2D& bb);
};

#endif // TERRAINPENTEX_H
