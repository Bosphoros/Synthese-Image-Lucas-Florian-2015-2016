#ifndef CSGTRANSLATION_H
#define CSGTRANSLATION_H
#include "csgunaire.h"

class CSGTranslation : public CSGUnaire
{
public:
    CSGTranslation(CSGNode * n);

    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects) const;
};

#endif // CSGTRANSLATION_H
