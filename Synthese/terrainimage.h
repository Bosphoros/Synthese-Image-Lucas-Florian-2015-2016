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
    TerrainImage(const QImage& i, double bl, double no, const Vector2D& a, const Vector2D& b);
    virtual double getHauteur(const Vector2D &p);
    virtual double getHauteurMin(const Vector2D& aa, const Vector2D& bb);
    virtual double getHauteurMax(const Vector2D& aa, const Vector2D& bb);
    virtual double getPenteMax(const Vector2D& aa, const Vector2D& bb);
};

#endif // TERRAINIMAGE_H
