#ifndef CSGUNION_H
#define CSGUNION_H
#include "csgbinaire.h"

class CSGUnion : public CSGBinaire
{
public:
    CSGUnion(CSGNode* n1,CSGNode* n2);
    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects, QVector<Vector3D>& normals) const;

};

#endif // CSGUNION_H
