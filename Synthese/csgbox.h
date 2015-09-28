#ifndef CSGBOX_H
#define CSGBOX_H
#include "csgprimitive.h"

class CSGBox: public CSGPrimitive
{
public:
    CSGBox();
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects) const;

};

#endif // CSGBOX_H
