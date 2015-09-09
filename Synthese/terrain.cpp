#include "terrain.h"
Terrain::Terrain():penteMax(-1)
{

}

QVector3D Terrain::norm(const QVector2D &p)
{
    QVector2D px(p.x()+epsilon,p.y());
    QVector2D py(p.x(),p.y()+epsilon);

    quint16 hp=getHauteur(p);
    quint16 hpx=getHauteur(px);
    quint16 hpy=getHauteur(py);

    QVector3D vp(p.x(),p.y(),(float)hp);

    QVector3D vpx(px.x(),px.y(),(float)hpx);

    QVector3D vpy(py.x(),py.y(),(float)hpy);

    QVector3D u=vpx-vp;
    QVector3D v=vpy-vp;

    QVector3D n(-u.z()/u.x(),1.0f,-v.z()/v.y());
    n.normalize();

    return n;

}


bool Terrain::isIn(const QVector3D &p)
{
    QVector2D p2(p.x(),p.z());
    return p.y()<=getHauteur(p2);
}

bool Terrain::isOut(const QVector3D &p)
{
    QVector2D p2(p.x(),p.z());
    return p.y()>getHauteur(p2);
}

QVector3D Terrain::intersect(Ray &r)
{

}

quint16 Terrain::getHauteurNormale(const QVector2D &p, QVector3D &n)
{
    n=norm(p);
    quint16 resu=getHauteur(p);
    return resu;
}

double Terrain::epsilon=0.00001;
