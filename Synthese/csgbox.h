#ifndef CSGBOX_H
#define CSGBOX_H
#include "csgprimitive.h"
#include "box.h"

class CSGBox: public CSGPrimitive, public Box
{
public:
    CSGBox();
    CSGBox(const Vector3D& aa, const Vector3D& bb);
    CSGBox(const Vector3D& c, float r);
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects, QVector<Vector3D>& normals) const;

};

#endif // CSGBOX_H
