#ifndef RAY_H
#define RAY_H
#include <QVector3D>
#include "terrain.h"
class Ray
{
private:
    static float pas;
public:
    const QVector3D origine;
    const QVector3D direction;
    Ray(QVector3D &o, QVector3D &d);
    QVector3D getPoint(float f);
    bool intersects(const QVector3D& a, const QVector3D& b, const QVector3D& c, QVector3D& out);
    int intersectsBox(const QVector3D& a, const QVector3D& b, QVector3D& in, QVector3D& out);
    bool intersectRayMarching(Terrain &t, const QVector3D &aBox, const QVector3D &bBox, QVector3D &resu, bool &isBox);
    bool intersectAdvanced(Terrain &t, QVector2D &a, QVector2D &b, QVector3D &resu);
};

#endif // RAY_H
