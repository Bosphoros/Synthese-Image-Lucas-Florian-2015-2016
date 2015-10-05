#include "csgbox.h"

CSGBox::CSGBox(const Vector3D &aa, const Vector3D &bb) : Box(aa, bb)
{

}

CSGBox::CSGBox(const Vector3D &c, float r) : Box(c, r)
{

}

bool CSGBox::isIn(const Vector3D &p) const
{
    return !(p.x() < a.x() || p.x() > b.x() || p.y() < a.y() || p.y() > b.y() || p.z() < a.z() || p.z() > b.x());

}

bool CSGBox::intersect(const Ray &r, QVector<double>& intersects, QVector<Vector3D> &normals) const
{
    Vector3D in, out;
    int nbInter = Box::intersect(r, in, out);
    double din = in.distanceToPoint(r.getOrigine());
    double dout = out.distanceToPoint(r.getOrigine());
    QVector<double> inters;
    if(nbInter == 2) {
        inters.push_back(din);
    }
    if(nbInter >= 1) {
        inters.push_back(dout);
    }
    intersects = inters;
    return nbInter > 0;
}

