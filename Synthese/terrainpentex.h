#ifndef TERRAINPENTEX_H
#define TERRAINPENTEX_H
#include "terrain.h"
#include <QVector2D>

class TerrainPenteX:public Terrain
{
public:
    TerrainPenteX(QVector2D& a, QVector2D& b);
    virtual float getHauteur(const QVector2D &p);
    virtual float getHauteurMin(QVector2D a,QVector2D b);
    virtual float getHauteurMax(QVector2D a,QVector2D b);
    virtual double getPenteMax(QVector2D a,QVector2D b);
};

#endif // TERRAINPENTEX_H
