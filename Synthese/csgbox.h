#ifndef CSGBOX_H
#define CSGBOX_H
#include "csgprimitive.h"

class CSGBox: public CSGPrimitive
{
public:
    CSGBox();
    virtual bool isIn(const Vector3D& p) const;
    virtual QVector<Vector3D>& intersect(const Ray& r) const;

};

#endif // CSGBOX_H
