#include "cylindre.h"

Cylindre::Cylindre()
{

}

Cylindre::Cylindre(const Vector3D& pointA, const Vector3D& pointB, double r, double h) : a(pointA), b(pointB), rayon(r), hauteur(h){

    u = (b-a).normalized();
}

double Cylindre::distanceToPoint(const Vector3D& p)
{

}

int Cylindre::intersect(const Ray& r, QVector<double>& li, QVector<Vector3D> &normals) const
{

    Vector3D d = r.getDirection();
    Vector3D o = r.getOrigine();

    //calcul des points d'intersections avec le cylindre infini.
    //solve t^2*(d.d - (d.u).(d.u)) + t*(2*(o-a).d-2*(d.u)*((o-a).u)) + (o-a).(o-a)-((o-a).u).((o-a).u))-R*R
    Vector3D ao = o-a;
    Vector3D dScalu = d*u;

    float x = (d*d - dScalu*dScalu);
    float y = (2*ao.d-2*dScalu*(oa*u));
    float z = ao*ao-(ao*u)*(oa.u)-R*R;

    float det = y*y - 4*(x*z);

    if(det < 0)
        return 0;
    else
        det = std::sqrt(det);

    float tca = (-y-det)/(2*x);
    float tcb = (-y+det)/(2*x);

    float tsa = -(ao*u/dScalu);
    float tsb = -(((o-b)*u)/dScalu);



}
