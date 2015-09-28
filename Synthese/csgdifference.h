#ifndef CSGDIFFERENCE_H
#define CSGDIFFERENCE_H
#include "csgbinaire.h"

class CSGDifference : public CSGBinaire
{
public:
    CSGDifference(CSGNode* n1,CSGNode* n2);
    virtual bool isIn(const Vector3D& p) const;
    virtual QVector<Vector3D>& intersect(const Ray& r) const;
};

#endif // CSGDIFFERENCE_H
