#include "terrainpentex.h"
#include <cmath>

TerrainPenteX::TerrainPenteX(Vector2D &a, Vector2D &b):Terrain(a,b)
{

}

double TerrainPenteX::getHauteur(const Vector2D &p)
{
    return 255/2*(sin(p.x()/100)+1);
}

double TerrainPenteX::getHauteurMin(const Vector2D &aa, const Vector2D &bb)
{
    return 0;
}

double TerrainPenteX::getHauteurMax(const Vector2D &aa, const Vector2D &bb)
{
    return 510;
}

double TerrainPenteX::getPenteMax(const Vector2D &aa, const Vector2D &bb)
{
    return 1;
}

