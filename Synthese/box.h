#ifndef BOX_H
#define BOX_H
#include "vector3d.h"
#include "ray.h"

class Box
{
private:
    const Vector3D a;
    const Vector3D b;
public:
    Box(const Vector3D& aa, const Vector3D& bb);
    int intersect(const Ray& r, Vector3D& in, Vector3D& out);
};

#endif // BOX_H
