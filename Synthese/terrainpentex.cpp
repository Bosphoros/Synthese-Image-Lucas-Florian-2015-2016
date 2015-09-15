#include "terrainpentex.h"
#include <cmath>

TerrainPenteX::TerrainPenteX(Vector2D &a, Vector2D &b):Terrain(a,b)
{

}

double TerrainPenteX::getHauteur(const Vector2D &p)
{
    return 255/2*(sin(p.x()/100)+1);
}

double TerrainPenteX::getHauteurMin() const
{
    return 0;
}

double TerrainPenteX::getHauteurMax() const
{
    return 510;
}

double TerrainPenteX::getPenteMax() const
{
    return 1;
}

