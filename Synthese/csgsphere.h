#ifndef CSGSPHERE_H
#define CSGSPHERE_H
#include "csgprimitive.h"

class CSGSphere : public CSGPrimitive
{
public:
    CSGSphere();
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects) const;

};

#endif // CSGSPHERE_H
