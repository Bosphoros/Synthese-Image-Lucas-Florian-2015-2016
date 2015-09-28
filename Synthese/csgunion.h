#ifndef CSGUNION_H
#define CSGUNION_H
#include "csgbinaire.h"

class CSGUnion : public CSGBinaire
{
public:
    CSGUnion(CSGNode* n1,CSGNode* n2);
    virtual bool isIn(const Vector3D& p) const;
    virtual QVector<Vector3D>& intersect(const Ray& r) const;
};

#endif // CSGUNION_H
