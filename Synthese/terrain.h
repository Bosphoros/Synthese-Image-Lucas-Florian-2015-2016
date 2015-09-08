#ifndef TERRAIN_H
#define TERRAIN_H

#include <QVector2D>
#include <QVector3D>

class Terrain
{

public:
    quint16 getHauteurNormale(QVector2D& p, QVector3D &n);

protected:
    static double epsilon;
    QVector3D norm(QVector2D& p);
    double penteMax=-1;
    QVector2D a;
    QVector2D b;
public:
    virtual quint16 getHauteur(QVector2D& p)=0;
    virtual quint16 getHauteurMin()=0;
    virtual quint16 getHauteurMax()=0;
    virtual double getPenteMax()=0;
};



#endif // TERRAIN_H