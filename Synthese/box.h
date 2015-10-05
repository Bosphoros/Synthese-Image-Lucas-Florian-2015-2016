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
    int intersect(const Ray& r, Vector3D& in, Vector3D& out, Vector3D& nin, Vector3D& nout) const;
    inline const Vector3D getA() const;
    inline const Vector3D getB() const;

};

inline const Vector3D Box::getA() const { return a; }
inline const Vector3D Box::getB() const { return b; }

#endif // BOX_H
