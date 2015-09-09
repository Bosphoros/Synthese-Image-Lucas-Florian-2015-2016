#ifndef RAY_H
#define RAY_H
#include <QVector3D>
class Ray
{
private:

public:
    const QVector3D origine;
    const QVector3D direction;
    Ray(QVector3D &o, QVector3D &d);
    QVector3D getPoint(float f);
};

#endif // RAY_H
