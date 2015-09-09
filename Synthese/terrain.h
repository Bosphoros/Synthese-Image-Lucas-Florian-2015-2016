#ifndef TERRAIN_H
#define TERRAIN_H

#include <QVector2D>
#include <QVector3D>
#include "ray.h"

class Terrain
{

public:
    float getHauteurNormale(const QVector2D& p, QVector3D &n);

protected:
    static double epsilon;
    QVector3D norm(const QVector2D &p);
    double penteMax;
public:
    Terrain();
    bool isIn(const QVector3D& p);
    bool isOut(const QVector3D& p);
    QVector3D intersect(Ray& r);
    virtual float getHauteur(const QVector2D& p)=0;
    virtual float getHauteurMin()=0;
    virtual float getHauteurMax()=0;
    virtual double getPenteMax()=0;
};



#endif // TERRAIN_H
