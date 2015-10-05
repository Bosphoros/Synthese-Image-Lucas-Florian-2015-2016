#include "sphere.h"

Sphere::Sphere(const Vector3D &c, double r) : centre(c), rayon(r)
{ }

double Sphere::distanceToPoint(const Vector3D &p)
{
    return centre.distanceToPoint(p) - rayon;
}

int Sphere::intersect(const Ray &r, QVector<double>& li, QVector<Vector3D> &normals) const
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
    QVector<Vector3D> norms;


    if(det == 0)
    {
        double t1 = l-det;
        Vector3D inter1 = r.getOrigine()+r.getDirection()*t1;

        norms.resize(1);
        list.resize(1);

        norms[0] = (inter1-centre).normalized();
        list[0] = t1;
        li = list;
        normals = norms;
        return 1;
    }

    double t1 = l-det;
    double t2 = l+det;

    Vector3D inter1 = r.getOrigine()+r.getDirection()*t1;
    Vector3D inter2 = r.getOrigine()+r.getDirection()*t2;

    norms.resize(2);
    list.resize(2);

    norms[0] = (inter1-centre).normalized();
    norms[1] = (inter2-centre).normalized();
    list[0] = l - det;
    list[1] = l + det;
    li = list;
    normals = norms;
    return 2;




}
