#ifndef CYLINDRE_H
#define CYLINDRE_H
#include "vector3d.h"
#include "ray.h"
#include <QVector>

class Cylindre
{

protected:
    Vector3D a;
    Vector3D b;
    double rayon;
    double hauteur;
    Vector3D u;
public:
    Cylindre();
    Cylindre(const Vector3D& pointA, const Vector3D& pointB, double r, double h);
    double distanceToPoint(const Vector3D& p);
    int intersect(const Ray& r, QVector<double>& li, QVector<Vector3D> &normals) const;

};

#endif // CYLINDRE_H
