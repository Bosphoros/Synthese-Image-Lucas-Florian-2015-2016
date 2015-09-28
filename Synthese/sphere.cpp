#include "sphere.h"

Sphere::Sphere(const Vector3D &c, double r) : centre(c), rayon(r)
{ }

double Sphere::distanceToPoint(const Vector3D &p)
{
    return centre.distanceToPoint(p) - rayon;
}

int Sphere::intersect(const Ray &r, QVector<double>& l)
{
    Vector3D oc = centre - r.getOrigine();		// Solve t^2*d.d + 2*t*(o-p).d + (o-p).(o-p)-R^2 = 0
    double t;
    double l = r.getDirection()*oc;
    double det = l * l - oc*oc + rayon*rayon;
    if (det < 0)
        return 0;
    else
        det = std::sqrt(det);

    QVector<double> list;
    if(det == 0) {
        list.resize(1);
        list[0] = l - det;
        l = list;
        return 1;
    }
    list.resize(2);
    list[0] = l - det;
    list[1] = l + det;
    l = list;
    return 2;

}
