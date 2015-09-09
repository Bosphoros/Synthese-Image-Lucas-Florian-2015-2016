#ifndef RAY_H
#define RAY_H
#include <QVector3D>
class Ray
{
private:
    QVector3D origine;
    QVector3D direction;
public:
    Ray(QVector3D &o, QVector3D &d);
    QVector3D getPoint(float f);
};

#endif // RAY_H
