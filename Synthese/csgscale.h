#ifndef CSGSCALE_H
#define CSGSCALE_H
#include "csgunaire.h"

class CSGScale : public CSGUnaire
{
public:
    CSGScale(CSGNode * n);

    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects) const;

};

#endif // CSGSCALE_H
