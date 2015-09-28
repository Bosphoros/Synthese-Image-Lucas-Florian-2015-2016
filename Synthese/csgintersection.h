#ifndef CSGINTERSECTION_H
#define CSGINTERSECTION_H
#include "csgbinaire.h"

class CSGIntersection : public CSGBinaire
{
public:
    CSGIntersection(CSGNode* n1,CSGNode* n2);

    virtual bool isIn(const Vector3D& p) const;
    virtual QVector<Vector3D>& intersect(const Ray& r) const;
};

#endif // CSGINTERSECTION_H
