#include "csgscale.h"

CSGScale::CSGScale(CSGNode *n): CSGUnaire(n)
{

}

bool CSGScale::isIn(const Vector3D &p) const
{
    return node->isIn((p-centre)/coefficient+centre);
}

bool CSGScale::intersect(const Ray &r, QVector<double>& intersects) const
{
    //on creer un nouveau rayon à partir du premier et selon l'homotéthie
    Ray newRay((r.getOrigine()-centre)/coefficient+centre,r.getDirection());

    return node->intersect(newRay, intersects);
}

