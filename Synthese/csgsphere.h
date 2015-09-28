#ifndef CSGSPHERE_H
#define CSGSPHERE_H
#include "csgprimitive.h"

class CSGSphere : public CSGPrimitive
{
public:
    CSGSphere();
    virtual bool isIn(const Vector3D& p) const;
    virtual QVector<Vector3D>& intersect(const Ray& r) const;

};

#endif // CSGSPHERE_H
