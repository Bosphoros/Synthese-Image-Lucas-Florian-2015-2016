#ifndef TERRAIN_H
#define TERRAIN_H

#include "vector2d.h"
#include "vector3d.h"
#include "ray.h"

class Terrain
{

public:
    double getHauteurNormale(const Vector2D& p, Vector3D &n);

protected:
    static double epsilon;
    Vector3D norm(const Vector2D &p);
    double penteMax;
    Vector2D a;
    Vector2D b;
    static double pas;
public:
    Terrain(const Vector2D& aa, const Vector2D& bb);
    bool isIn(const Vector3D& p);
    bool isOut(const Vector3D& p);
    virtual double getHauteur(const Vector2D& p)=0;
    virtual double getHauteurMin(Vector2D a,Vector2D b)=0;
    virtual double getHauteurMax(Vector2D a,Vector2D b)=0;
    virtual double getPenteMax(Vector2D a,Vector2D b)=0;
    bool intersectRayMarching(const Ray &r, const Vector3D &aBox, const Vector3D &bBox, Vector3D &resu, bool &isBox);
    bool intersectAdvanced(const Ray &r, const Vector2D &aa, const Vector2D &bb, Vector3D &resu) const;
};



#endif // TERRAIN_H
