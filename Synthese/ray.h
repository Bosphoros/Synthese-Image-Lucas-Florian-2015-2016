#ifndef RAY_H
#define RAY_H
#include "vector3d.h"
class Ray
{
private:
    static double pas;
public:
    const Vector3D origine;
    const Vector3D direction;
    Ray(const Vector3D &o, const Vector3D &d);
    Vector3D getPoint(double f) const;
    bool intersects(const Vector3D& a, const Vector3D& b, const Vector3D& c, Vector3D& out) const;
    int intersectsBox(const Vector3D& a, const Vector3D& b, Vector3D& in, Vector3D& out) const;

};

    inline Vector3D Ray::getPoint(double f) const{
        return origine+direction*f;
    }

#endif // RAY_H
