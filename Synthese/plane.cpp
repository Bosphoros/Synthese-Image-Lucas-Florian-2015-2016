#include "plane.h"

Plane::Plane(const Vector3D &n, const Vector3D &p) : normal(n), point(p)
{

}

Plane::Plane(const Vector3D &a, const Vector3D &b, const Vector3D &c) : point(a)
{
    // Vecteurs du plan
    Vector3D u(c - a);
    Vector3D v(b - a);
    normal = u^v;
}

bool Plane::intersects(const Ray &r, Vector3D &out)
{
    // Produit scalaire, si 0 pas de solution ou une infinité
    double scalaire = r.getDirection()*normal;//Vector3D::dotProduct(direction, w); //direction.x()*w.x()+direction.y()*w.y()+direction.z()*w.z();

    if(std::abs(scalaire) < 0.0001)
        return false;
    double delta = point*normal;//Vector3D::dotProduct(a, w);

    double t = (delta - r.getOrigine()*normal)/scalaire; //Vector3D::dotProduct(origine, w)


    out = r.getPoint(t);
    return true;
}

