#ifndef CAMERA_H
#define CAMERA_H
#include "vector3d.h"
#include <QImage>
#include <QRgb>
#include "terrain.h"

class Camera
{
private:
    Vector3D origine;
    Vector3D w;
    Vector3D u;
    Vector3D v;
    double dw;
    double lw;
    double lh;
public:
    Camera(const Vector3D& o, const Vector3D& at,double d);
    QRgb ptScreen(Terrain* const t, const Vector3D &aBox, const Vector3D &bBox, const Vector3D &s, int i, int j, int l, int h) const;
    QImage printScreen(Terrain * const t, const Vector3D& s, int l, int h) const;
    void translate(const Vector3D& v);

};

#endif // CAMERA_H
