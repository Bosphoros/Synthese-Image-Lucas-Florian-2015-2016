#ifndef BOX_H
#define BOX_H
#include "vector3d.h"
#include "ray.h"

class Box
{
protected:
    Vector3D a;
    Vector3D b;
public:
    Box();
    Box(const Vector3D& aa, const Vector3D& bb);
    Box(const Vector3D &c, float r);
    int intersect(const Ray& r, Vector3D& in, Vector3D& out) const;

};

#endif // BOX_H
