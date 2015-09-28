#ifndef SPHERE_H
#define SPHERE_H
#include "vector3d.h"
#include "ray.h"
#include <QVector>

class Sphere
{
protected:
    const Vector3D centre;
    const double rayon;
public:
    Sphere(const Vector3D& c, double r);
    double distanceToPoint(const Vector3D& p);
    int intersect(const Ray& r, QVector<double>& l) const;
};

#endif // SPHERE_H
