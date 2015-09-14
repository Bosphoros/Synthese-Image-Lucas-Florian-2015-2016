#include "terrainpentex.h"
#include <cmath>

TerrainPenteX::TerrainPenteX(QVector2D &a, QVector2D &b):Terrain(a,b)
{

}

float TerrainPenteX::getHauteur(const QVector2D &p)
{
    return 255/2*(sin(p.x()/100)+1);
}

float TerrainPenteX::getHauteurMin(QVector2D a, QVector2D b)
{
    return 0;
}

float TerrainPenteX::getHauteurMax(QVector2D a, QVector2D b)
{
    return 510;
}

double TerrainPenteX::getPenteMax(QVector2D a, QVector2D b)
{
    return 1;
}

