#ifndef TERRAIN_H
#define TERRAIN_H

#include <QVector2D>
#include <QVector3D>

class Terrain
{

public:
    float getHauteurNormale(const QVector2D& p, QVector3D &n);

protected:
    static double epsilon;
    QVector3D norm(const QVector2D &p);
    double penteMax;
    QVector2D a;
    QVector2D b;

public:
    Terrain(const QVector2D& aa, const QVector2D& bb);
    bool isIn(const QVector3D& p);
    bool isOut(const QVector3D& p);
    virtual float getHauteur(const QVector2D& p)=0;
    virtual float getHauteurMin(QVector2D a,QVector2D b)=0;
    virtual float getHauteurMax(QVector2D a,QVector2D b)=0;
    virtual double getPenteMax(QVector2D a,QVector2D b)=0;
};



#endif // TERRAIN_H
