#include "csgdifference.h"

CSGDifference::CSGDifference(CSGNode *n1, CSGNode *n2):CSGBinaire(n1,n2)
{

}

bool CSGDifference::isIn(const Vector3D &p) const
{

}

bool CSGDifference::intersect(const Ray &r, QVector<double>& intersects) const
{

}
