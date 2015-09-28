#include "csgsphere.h"

CSGSphere::CSGSphere()
{

}

bool CSGSphere::isIn(const Vector3D &p) const
{
    return (p.distanceToPointSquared(centre) < rayon);
}

bool &CSGSphere::intersect(const Ray &r, QVector<double> &t) const
{
    return Sphere::intersect(r,t);
}

