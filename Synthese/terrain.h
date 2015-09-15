#ifndef TERRAIN_H
#define TERRAIN_H

#include "vector2d.h"
#include "vector3d.h"
#include "ray.h"

class Terrain
{

public:


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
    double getHauteurNormale(const Vector2D& p, Vector3D &n);
    virtual double getHauteur(const Vector2D& p) const =0;
    virtual double getHauteurMin() const =0;
    virtual double getHauteurMax() const =0;
    virtual double getPenteMax() const =0;
    Vector2D getA() const;
    Vector2D getB() const;
    bool intersectRayMarching(const Ray &r, const Vector3D &aBox, const Vector3D &bBox, Vector3D &resu, bool &isBox);
    bool intersectAdvanced(const Ray &r, const Vector2D &aa, const Vector2D &bb, Vector3D &resu) const;
};

    inline Vector2D Terrain::getA() const{
        return a;
    }

    inline Vector2D Terrain::getB() const{
        return b;
    }



#endif // TERRAIN_H
