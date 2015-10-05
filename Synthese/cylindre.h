#ifndef CYLINDRE_H
#define CYLINDRE_H
#include "vector3d.h"
#include "ray.h"
#include <QVector>

class Cylindre
{

protected:
    const Vector3D a;
    const Vector3D b;
    const double rayon;
    const double hauteur;
    const QVector u;
public:
    Cylindre();
    Cylindre(const Vector3D& pointA, const Vector3D& pointB, double r, double h);
    double distanceToPoint(const Vector3D& p);
    int intersect(const Ray& r, QVector<double>& li, QVector<Vector3D> &normals) const;

};

#endif // CYLINDRE_H
