#include "csgtranslation.h"

CSGTranslation::CSGTranslation(CSGNode *n, Vector3D t): CSGUnaire(n),trans(t)
{

}

bool CSGTranslation::isIn(const Vector3D &p) const
{
    Vector3D pTemp=p-trans;
    return node->isIn(pTemp);

}

bool CSGTranslation::intersect(const Ray &r, QVector<double>& intersects, QVector<Vector3D> &normals) const
{
    Ray rTemp(r.getOrigine()-trans,r.getDirection());
    return node->intersect(rTemp,intersects, normals);
}

