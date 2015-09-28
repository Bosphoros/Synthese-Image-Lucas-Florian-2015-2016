#include "csgtranslation.h"

CSGTranslation::CSGTranslation(CSGNode *n, Vector3D t): CSGUnaire(n),trans(t)
{

}

bool CSGTranslation::isIn(const Vector3D &p) const
{
    Vector3D pTemp=p-trans;
    return node->isIn(ptemp);

}

bool CSGTranslation::intersect(const Ray &r, QVector<double>& intersects) const
{
    Ray rTemp(r.origine-trans,r.direction);
    return node->intersect(rTemp,intersects);
}

