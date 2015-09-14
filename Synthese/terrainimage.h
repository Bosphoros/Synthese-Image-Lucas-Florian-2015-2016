#ifndef TERRAINIMAGE_H
#define TERRAINIMAGE_H
#include "terrain.h"
#include <QImage>
class TerrainImage : public Terrain
{
private:
    std::vector<quint8> mat;
    int w;
    int h;

public:
    TerrainImage(QImage& i, bool blanc,const QVector2D& a,const QVector2D& b);
    virtual float getHauteur(const QVector2D &p);
    virtual float getHauteurMin(QVector2D a,QVector2D b);
    virtual float getHauteurMax(QVector2D a,QVector2D b);
    virtual double getPenteMax(QVector2D a,QVector2D b);
};

#endif // TERRAINIMAGE_H
