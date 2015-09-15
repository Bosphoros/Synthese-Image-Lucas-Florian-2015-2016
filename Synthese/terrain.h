#ifndef TERRAIN_H
#define TERRAIN_H

#include "vector2d.h"
#include "vector3d.h"

class Terrain
{

public:
    float getHauteurNormale(const Vector2D& p, Vector3D &n);

protected:
    static double epsilon;
    Vector3D norm(const Vector2D &p);
    double penteMax;
    Vector2D a;
    Vector2D b;

public:
    Terrain(const Vector2D& aa, const Vector2D& bb);
    bool isIn(const Vector3D& p);
    bool isOut(const Vector3D& p);
    virtual float getHauteur(const Vector2D& p)=0;
    virtual float getHauteurMin(Vector2D a,Vector2D b)=0;
    virtual float getHauteurMax(Vector2D a,Vector2D b)=0;
    virtual double getPenteMax(Vector2D a,Vector2D b)=0;
};



#endif // TERRAIN_H
