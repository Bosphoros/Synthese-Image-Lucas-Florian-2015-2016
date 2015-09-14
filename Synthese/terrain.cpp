#include "terrain.h"
#include <iostream>
Terrain::Terrain(const QVector2D &aa, const QVector2D &bb):penteMax(-1),a(aa),b(bb)
{

}

QVector3D Terrain::norm(const QVector2D &p)
{
   /* QVector2D px(p.x()+epsilon,p.y());
    QVector2D py(p.x(),p.y()+epsilon);

    float hp=getHauteur(p);
    float hpx=getHauteur(px);
    float hpy=getHauteur(py);

    QVector3D vp(p.x(),p.y(),(float)hp);

    QVector3D vpx(px.x(),px.y(),(float)hpx);

    QVector3D vpy(py.x(),py.y(),(float)hpy);

    QVector3D u=vpx-vp;
    QVector3D v=vpy-vp;

    QVector3D n(-u.z()/u.x(),1.0f,-v.z()/v.y());
    n.normalize();

    return n;*/

    //std::cout<<p.x()<<" "<<p.x()+epsilon<<std::endl;

    QVector2D px(p.x()+epsilon,p.y());
    QVector2D pxminus(p.x()-epsilon, p.y());
    QVector2D py(p.x(),p.y()+epsilon);
    QVector2D pyminus(p.x(),p.y()-epsilon);

    float hpx=getHauteur(px);
    float hpxminus = getHauteur(pxminus);
    float hpy=getHauteur(py);
    float hpyminus = getHauteur(pyminus);
    //std::cout<<hpx<<" "<<hpxminus<<std::endl;
    QVector3D resu(-(hpx-hpxminus),2*epsilon,-(hpy-hpyminus));
    resu.normalize();
    return resu;


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

float Terrain::getHauteurNormale(const QVector2D &p, QVector3D &n)
{
    n=norm(p);
    quint16 resu=getHauteur(p);
    return resu;
}

double Terrain::epsilon=0.001;

