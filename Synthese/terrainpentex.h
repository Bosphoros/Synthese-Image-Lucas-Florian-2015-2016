#ifndef TERRAINPENTEX_H
#define TERRAINPENTEX_H
#include "terrain.h"
#include "vector2d.h"

class TerrainPenteX:public Terrain
{
public:
    TerrainPenteX(Vector2D& a, Vector2D& b);
    virtual double getHauteur(const Vector2D &p);
    virtual double getHauteurMin(Vector2D a,Vector2D b);
    virtual double getHauteurMax(Vector2D a,Vector2D b);
    virtual double getPenteMax(Vector2D a,Vector2D b);
};

#endif // TERRAINPENTEX_H
