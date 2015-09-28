#ifndef CSGTRANSLATION_H
#define CSGTRANSLATION_H
#include "csgunaire.h"

class CSGTranslation : public CSGUnaire
{
protected:
    Vector3D trans;
public:
    CSGTranslation(CSGNode * n, Vector3D t);

    virtual bool isIn(const Vector3D& p) const;
    virtual bool intersect(const Ray& r, QVector<double>& intersects) const;
};

#endif // CSGTRANSLATION_H
