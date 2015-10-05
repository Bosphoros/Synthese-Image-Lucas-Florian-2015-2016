#ifndef CSGINTERSECTION_H
#define CSGINTERSECTION_H
#include "csgbinaire.h"

class CSGIntersection : public CSGBinaire
{
public:
    CSGIntersection(CSGNode* n1,CSGNode* n2);

    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects, QVector<Vector3D>& normals) const;
};

#endif // CSGINTERSECTION_H
