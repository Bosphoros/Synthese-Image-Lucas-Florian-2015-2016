#ifndef PLANE_H
#define PLANE_H
#include "vector3d.h"
#include "ray.h"

class Plane
{
private:
    Vector3D normal;
    Vector3D point;
public:
    Plane(const Vector3D& n, const Vector3D& p);
    Plane(const Vector3D &a, const Vector3D& b, const Vector3D& c);
    bool intersects(const Ray& r, Vector3D& out);

};

#endif // PLANE_H
