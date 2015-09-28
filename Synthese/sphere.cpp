#include "sphere.h"

Sphere::Sphere(const Vector3D &c, double r) : centre(c), rayon(r)
{ }

double Sphere::distanceToPoint(const Vector3D &p)
{
    return centre.distanceToPoint(p) - rayon;
}

int Sphere::intersect(const Ray &r)
{
    //d*d*t*t+(2*(r.getOrigine()-centre)*d)+((r.getOrigine()-centre)*(r.getOrigine()-centre)-rayon*rayon);
}
