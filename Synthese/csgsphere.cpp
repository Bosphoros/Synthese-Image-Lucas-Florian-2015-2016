#include "csgsphere.h"

CSGSphere::CSGSphere()
{

}

bool CSGSphere::isIn(const Vector3D &p) const
{
    return false;
}

bool CSGSphere::intersect(const Ray &r, QVector<double>& intersects) const
{
    return QVector<Vector3D>;
}

