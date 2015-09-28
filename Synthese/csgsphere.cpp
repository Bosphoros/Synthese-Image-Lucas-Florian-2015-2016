#include "csgsphere.h"

CSGSphere::CSGSphere(const Vector3D c, double r):CSGPrimitive(),Sphere(c,r)
{

}

bool CSGSphere::isIn(const Vector3D &p) const
{
    return (p.distanceToPointSquared(centre) < rayon*rayon);
}

bool CSGSphere::intersect(const Ray &r, QVector<double>& intersects) const
{
    return Sphere::intersect(r,intersects);
}

