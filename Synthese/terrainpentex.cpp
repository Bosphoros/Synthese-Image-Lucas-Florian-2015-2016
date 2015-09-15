#include "terrainpentex.h"
#include <cmath>

TerrainPenteX::TerrainPenteX(Vector2D &a, Vector2D &b):Terrain(a,b)
{

}

double TerrainPenteX::getHauteur(const Vector2D &p)
{
    return 255/2*(sin(p.x()/100)+1);
}

double TerrainPenteX::getHauteurMin(Vector2D a, Vector2D b)
{
    return 0;
}

double TerrainPenteX::getHauteurMax(Vector2D a, Vector2D b)
{
    return 510;
}

double TerrainPenteX::getPenteMax(Vector2D a, Vector2D b)
{
    return 1;
}

