#ifndef CSGDIFFERENCE_H
#define CSGDIFFERENCE_H
#include "csgbinaire.h"

class CSGDifference : public CSGBinaire
{
public:
    CSGDifference(CSGNode* n1,CSGNode* n2);
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects, QVector<Vector3D>& normals) const;

};

#endif // CSGDIFFERENCE_H
