#include "camera.h"
#include "ray.h"
#include <QColor>
#include <iostream>
#include <cmath>

Camera::Camera(const Vector3D &o, const Vector3D &at, double d):origine(o),dw(d)
{
    Vector3D oat=(at-o);
    w=oat.normalized();
    u=-(w^Vector3D(0,1,0)).normalized();
    v= (w^u).normalized();
    lh=1;
    lw=16/9;
}

QRgb Camera::ptScreen(Terrain * const t, const Vector3D& aBox, const Vector3D& bBox, const Vector3D& s, int i, int j, int l, int h,double pMax) const
{
    double x=i*2*lw/l-lw;
    double y=j*2*lh/h-lh;

    Vector3D pt =origine+(dw*w)+(x*u)+(y*v);
    Vector3D dir(pt-origine);
    dir.normalize();
    Ray r(origine,dir);

    //std::cout << origine.x()  <<", "<<origine.y()<<", "<<origine.z()<<"/"<<dir.x()<<", "<<dir.y()<<", "<<dir.z()<< std::endl;
    Vector3D inter;
    bool isBox=false;
//   if(!t->intersectRayMarching(r,aBox,bBox,inter,isBox)){
    if(!t->intersectAdvanced(r,aBox,bBox,pMax,inter,isBox)){
        QColor couleur(0,0,255,255);
        return couleur.rgb();
    }

    //std::cout << "Touch" << std::endl;
    Vector3D normale;
    t->getHauteurNormale(Vector2D(inter.x(),inter.z()),normale);
    if(isBox) {
        QColor couleur(255,0,0,255);
        return couleur.rgb();
    }
    //std::cout << normale.x()  <<", "<<normale.y()<<", "<<normale.z()<<std::endl;
    double lu=normale*(-s);
    //std::cout <<lu<<std::endl;
    if(lu<0)
        lu=0;


    lu*=200.0;

    if(lu>255)
        lu=255;

    QColor couleur(lu,lu,lu,255);
    return couleur.rgb();


}

QImage Camera::printScreen(Terrain * const t, const Vector3D& s, int l, int h) const
{
    double pMax=t->getPenteMax();
    QImage im(l,h,QImage::Format_ARGB32);
    double min=t->getHauteurMin();
    double max=t->getHauteurMax();
    Vector3D aBox(t->getA().x(),min,t->getA().y());
    Vector3D bBox(t->getB().x(),max*1.5,t->getB().y());

    for(int i=0;i<l;++i){
        for(int j=0;j<h;++j){
            im.setPixel(i,h-1-j,ptScreen(t,aBox,bBox,s,i,j,l,h,pMax));
        }
    }

    return im;

}

void Camera::translate(const Vector3D &v)
{
    origine+=v;
}

