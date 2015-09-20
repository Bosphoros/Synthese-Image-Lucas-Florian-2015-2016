#ifndef TERRAINPENTEX_H
#define TERRAINPENTEX_H
#include "terrain.h"
#include "vector2d.h"
#include <cmath>

/**
 * @brief The TerrainPenteX class, test class
 */
class TerrainPenteX:public Terrain
{
public:
    TerrainPenteX(Vector2D& a, Vector2D& b);
    virtual double getHauteur(const Vector2D &p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

inline TerrainPenteX::TerrainPenteX(Vector2D &a, Vector2D &b):Terrain(a,b)
{

}

inline double TerrainPenteX::getHauteur(const Vector2D &p) const
{
    return 255/2*(sin(p.x()/100)+1);
}

inline double TerrainPenteX::getHauteurMin() const
{
    return 0;
}

inline double TerrainPenteX::getHauteurMax() const
{
    return 510;
}

inline double TerrainPenteX::getPenteMax() const
{
    return 1;
}


#endif // TERRAINPENTEX_H
