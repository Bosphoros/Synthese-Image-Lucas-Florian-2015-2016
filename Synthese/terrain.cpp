#include "terrain.h"
#include <iostream>
Terrain::Terrain(const Vector2D &aa, const Vector2D &bb):penteMax(-1),a(aa),b(bb)
{

}

Vector3D Terrain::norm(const Vector2D &p)
{
   /* Vector2D px(p.x()+epsilon,p.y());
    Vector2D py(p.x(),p.y()+epsilon);

    float hp=getHauteur(p);
    float hpx=getHauteur(px);
    float hpy=getHauteur(py);

    Vector3D vp(p.x(),p.y(),(float)hp);

    Vector3D vpx(px.x(),px.y(),(float)hpx);

    Vector3D vpy(py.x(),py.y(),(float)hpy);

    Vector3D u=vpx-vp;
    Vector3D v=vpy-vp;

    Vector3D n(-u.z()/u.x(),1.0f,-v.z()/v.y());
    n.normalize();

    return n;*/

    //std::cout<<p.x()<<" "<<p.x()+epsilon<<std::endl;

    Vector2D px(p.x()+epsilon,p.y());
    Vector2D pxminus(p.x()-epsilon, p.y());
    Vector2D py(p.x(),p.y()+epsilon);
    Vector2D pyminus(p.x(),p.y()-epsilon);

    float hpx=getHauteur(px);
    float hpxminus = getHauteur(pxminus);
    float hpy=getHauteur(py);
    float hpyminus = getHauteur(pyminus);
    //std::cout<<hpx<<" "<<hpxminus<<std::endl;
    Vector3D resu(-(hpx-hpxminus),2*epsilon,-(hpy-hpyminus));
    resu.normalize();
    return resu;


}


bool Terrain::isIn(const Vector3D &p)
{
    Vector2D p2(p.x(),p.z());
    return p.y()<=getHauteur(p2);
}

bool Terrain::isOut(const Vector3D &p)
{
    Vector2D p2(p.x(),p.z());
    return p.y()>getHauteur(p2);
}

float Terrain::getHauteurNormale(const Vector2D &p, Vector3D &n)
{
    n=norm(p);
    double resu=getHauteur(p);
    return resu;
}

double Terrain::epsilon=0.001;

