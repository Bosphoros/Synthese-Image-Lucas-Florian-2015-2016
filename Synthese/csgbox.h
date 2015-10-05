#ifndef CSGBOX_H
#define CSGBOX_H
#include "csgprimitive.h"

class CSGBox: public CSGPrimitive
{
public:
    CSGBox();
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects, QVector<Vector3D>& normals) const;

};

#endif // CSGBOX_H
