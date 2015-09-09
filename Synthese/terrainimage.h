#ifndef TERRAINIMAGE_H
#define TERRAINIMAGE_H
#include "terrain.h"
#include <QImage>
class TerrainImage : public Terrain
{
private:
    std::vector<quint8> mat;
    quint16 longueur;
    quint16 largeur;
    int w;
    int h;
    QVector2D a;
    QVector2D b;

public:
    TerrainImage(QImage& i, quint16 lo,quint16 la,QVector2D& aa,QVector2D& bb);
    virtual float getHauteur(const QVector2D &p);
    virtual float getHauteurMin();
    virtual float getHauteurMax();
    virtual double getPenteMax();
};

#endif // TERRAINIMAGE_H
