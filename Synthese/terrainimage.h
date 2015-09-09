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

public:
    TerrainImage(QImage& i, quint16 lo,quint16 la,QVector2D& aa,QVector2D& bb);
    virtual quint16 getHauteur(const QVector2D &p);
    virtual quint16 getHauteurMin();
    virtual quint16 getHauteurMax();
    virtual double getPenteMax();
};

#endif // TERRAINIMAGE_H
