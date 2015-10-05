#ifndef CSGSPHERE_H
#define CSGSPHERE_H
#include "csgprimitive.h"
#include "sphere.h"

class CSGSphere : public CSGPrimitive, public Sphere
{
public:
    CSGSphere(const Vector3D c, double r);
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects, QVector<Vector3D>& normals) const;

};

#endif // CSGSPHERE_H
