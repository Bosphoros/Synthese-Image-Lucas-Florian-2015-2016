#ifndef TERRAINPENTEX_H
#define TERRAINPENTEX_H
#include "terrain.h"
#include "vector2d.h"
#include <cmath>
#include "smoothnoise.h"
#include "mathutils.h"

/**
 * @brief The TerrainPenteX class, test class
 */
class TerrainPenteX:public Terrain
{
public:
    TerrainPenteX(Vector2D& a, Vector2D& b);
    virtual double getHauteur(const Vector2D &p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

inline TerrainPenteX::TerrainPenteX(Vector2D &a, Vector2D &b):Terrain(a,b)
{

}

inline double TerrainPenteX::getHauteur(const Vector2D &p) const
{
    //return 255/2*(sin(p.x()/100)+1);
    double h = 0;
    double th = 150*raw_noise_2d(p.x()*(1/600.0), p.y()*(1/600.0));
    th=MathUtils::ridge(th, 90+10*raw_noise_2d(p.x()*(1/200.0), p.y()*(1/200.0)));
    h+=th;
    th=((-15)+30*raw_noise_2d(p.x()*(1/160.0)+0.335, p.y()*(1/160.0)))*MathUtils::fonctionQuadratique(50, 100, h);
    th=MathUtils::ridge(th, 8+2*raw_noise_2d(p.x()*(1/50.0), p.y()*(1/50.0)));
    h += th;
    th=3*raw_noise_2d(p.x()*(1/20.0), p.y()*(1/20.0))*MathUtils::fonctionQuadratique(80, 90, h);
    //th=MathUtils::ridge(th, 2+0.5*raw_noise_2d(p.x()*(1/8.0), p.y()*(1/8.0)));
    h += th;

    th=1*raw_noise_2d(p.x()*(1/40.0), p.y()*(1/40.0))*MathUtils::fonctionQuadratiqueInv(0, 150, h);
    h += th;
    return h;
}

inline double TerrainPenteX::getHauteurMin() const
{
    return 0;
}

inline double TerrainPenteX::getHauteurMax() const
{
    return 510;
}

inline double TerrainPenteX::getPenteMax() const
{
    return 1;
}


#endif // TERRAINPENTEX_H
