#ifndef CSGROTATION_H
#define CSGROTATION_H
#include "csgunaire.h"

class CSGRotation : public CSGUnaire
{
public:
    CSGRotation(CSGNode * n);

    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects) const;

};

#endif // CSGROTATION_H
