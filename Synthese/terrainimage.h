#ifndef TERRAINIMAGE_H
#define TERRAINIMAGE_H

#ifndef fmin
    #define fmin(a,b) a<b?a:b
#endif
#ifndef fmax
    #define fmax(a,b) a>b?a:b
#endif

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
    virtual double getHauteur(const Vector2D &p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

inline double TerrainImage::getHauteurMax() const
{
    return fmax(blanc,noir);
}

inline double TerrainImage::getHauteurMin() const
{
    return fmin(blanc,noir);
}

#endif // TERRAINIMAGE_H
