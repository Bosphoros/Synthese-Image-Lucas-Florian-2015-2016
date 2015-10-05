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
    Vector3D in, out, nin, nout;
    int nbInter = Box::intersect(r, in, out, nin, nout);
    double din = in.distanceToPoint(r.getOrigine());
    double dout = out.distanceToPoint(r.getOrigine());
    QVector<double> inters;
    QVector<Vector3D> norms;
    if(nbInter == 2) {
        inters.push_back(din);
        norms.push_back(nin);
    }
    if(nbInter >= 1) {
        inters.push_back(dout);
        norms.push_back(nout);
    }
    intersects = inters;
    normals = norms;
    return nbInter > 0;
}

