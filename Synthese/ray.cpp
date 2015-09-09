#include "ray.h"

Ray::Ray(QVector3D& o, QVector3D& d):origine(o),direction(d.normalized())
{
}

QVector3D Ray::getPoint(float f)
{
    return origine+f*direction;
}
