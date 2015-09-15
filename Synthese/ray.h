#ifndef RAY_H
#define RAY_H
#include "vector3d.h"
#include "terrain.h"
class Ray
{
private:
    static double pas;
public:
    const Vector3D origine;
    const Vector3D direction;
    Ray(Vector3D &o, Vector3D &d);
    Vector3D getPoint(double f);
    bool intersects(const Vector3D& a, const Vector3D& b, const Vector3D& c, Vector3D& out);
    int intersectsBox(const Vector3D& a, const Vector3D& b, Vector3D& in, Vector3D& out);
    bool intersectRayMarching(Terrain &t, const Vector3D &aBox, const Vector3D &bBox, Vector3D &resu, bool &isBox);
    bool intersectAdvanced(Terrain &t, Vector2D &a, Vector2D &b, Vector3D &resu);
};

#endif // RAY_H
