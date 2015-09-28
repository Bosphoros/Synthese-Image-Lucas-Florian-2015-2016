#ifndef CSGSPHERE_H
#define CSGSPHERE_H
#include "csgprimitive.h"
#include "sphere.h"

class CSGSphere : public CSGPrimitive, public Sphere
{
public:
    CSGSphere();
    virtual bool isIn(const Vector3D& p) const;
    virtual bool &intersect(const Ray& r, QVector<double> &t) const;

};

#endif // CSGSPHERE_H
