#ifndef CSGDIFFERENCE_H
#define CSGDIFFERENCE_H
#include "csgbinaire.h"

class CSGDifference : public CSGBinaire
{
public:
    CSGDifference(CSGNode* n1,CSGNode* n2);
    virtual bool isIn(const Vector3D& p) const;
    virtual bool& intersect(const Ray& r, Qvector<double> &t) const;
};

#endif // CSGDIFFERENCE_H
