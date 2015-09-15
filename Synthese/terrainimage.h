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
    TerrainImage(QImage& i, bool blanc,const Vector2D& a,const Vector2D& b);
    virtual float getHauteur(const Vector2D &p);
    virtual float getHauteurMin(Vector2D a,Vector2D b);
    virtual float getHauteurMax(Vector2D a,Vector2D b);
    virtual double getPenteMax(Vector2D a,Vector2D b);
};

#endif // TERRAINIMAGE_H
