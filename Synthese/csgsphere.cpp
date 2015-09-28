#include "csgsphere.h"

CSGSphere::CSGSphere()
{

}

bool CSGSphere::isIn(const Vector3D &p) const
{
    return false;
}

QVector<Vector3D> &CSGSphere::intersect(const Ray &r) const
{
    return QVector<Vector3D>;
}

