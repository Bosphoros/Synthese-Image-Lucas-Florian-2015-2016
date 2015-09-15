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
    double blanc;
    double noir;

public:
    TerrainImage(QImage& i, double bl, double no, const Vector2D& a, const Vector2D& b);
    virtual double getHauteur(const Vector2D &p);
    virtual double getHauteurMin(Vector2D aa, Vector2D bb);
    virtual double getHauteurMax(Vector2D aa, Vector2D bb);
    virtual double getPenteMax(Vector2D a,Vector2D b);
};

#endif // TERRAINIMAGE_H
