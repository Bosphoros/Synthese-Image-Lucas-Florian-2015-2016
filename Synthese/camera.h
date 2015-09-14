#ifndef CAMERA_H
#define CAMERA_H
#include <QVector3D>
#include <QImage>
#include <QRgb>
#include "terrain.h"

class Camera
{
private:
    QVector3D origine;
    QVector3D w;
    QVector3D u;
    QVector3D v;
    double dw;
    double lw;
    double lh;
public:
    Camera(QVector3D& o, QVector3D& at);
    QRgb ptScreen(Terrain& t, const QVector3D &aBox, const QVector3D &bBox, const QVector3D &s, int i, int j, int l, int h);
    QImage printScreen(Terrain& t, const QVector2D &a, const QVector2D &b, const QVector3D &s, int l, int h);

};

#endif // CAMERA_H
