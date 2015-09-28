#include "camera.h"
#include "ray.h"
#include <QColor>
#include <iostream>
#include <cmath>

Camera::Camera(Vector3D &o, Vector3D &at):origine(o)
{
    Vector3D oat=(at-o);
    w=oat.normalized();
    dw=oat.length();
    u=-(w^Vector3D(0,1,0)).normalized();
    v= (w^u).normalized();
    lh=1;
    lw=16/9;


}

QRgb Camera::ptScreen(Terrain &t,const Vector3D& aBox, const Vector3D& bBox, const Vector3D& s, int i, int j, int l, int h)
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
    if(!r.intersectRayMarching(t,aBox,bBox,inter,isBox)){
        QColor couleur(0,0,255,255);
        return couleur.rgb();
    }

    //std::cout << "Touch" << std::endl;
    Vector3D normale;
    double hauteur = t.getHauteurNormale(Vector2D(inter.x(),inter.z()),normale);
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

QImage Camera::printScreen(Terrain &t,const Vector2D& a, const Vector2D& b, const Vector3D& s, int l, int h)
{
    QImage im(l,h,QImage::Format_ARGB32);
    double min=t.getHauteurMin(a,b);
    double max=t.getHauteurMax(a,b);
    Vector3D aBox(a.x(),min,a.y());
    Vector3D bBox(b.x(),max*1.5,b.y());

    for(int i=0;i<l;++i){
        for(int j=0;j<h;++j){
            im.setPixel(i,h-1-j,ptScreen(t,aBox,bBox,s,i,j,l,h));
        }
    }

    return im;

}

QRgb Camera::ptScreen(CSGNode &t, const Vector3D &s, int i, int j, int l, int h)
{

    double x=i*2*lw/l-lw;
    double y=j*2*lh/h-lh;

    Vector3D pt =origine+(dw*w)+(x*u)+(y*v);
    Vector3D dir(pt-origine);
    dir.normalize();
    Ray r(origine,dir);
    QVector<double> intersects;
    if(!t.intersect(r,intersects)){
        QColor couleur(0,0,0,0);
        return couleur.rgba();
    }

         double d=intersects.at(0);

         for(int i=1;i<intersects.size();++i){
             if(d>intersects.at(i))
                 d=intersects.at(i);
         }

          Vector3D inter=r.getPoint(d);

          QColor couleur(0,0,255,255);
          return couleur.rgba();

}

QImage Camera::printScreen(CSGNode &node, const Vector3D &s, int l, int h)
{
    QImage im(l,h,QImage::Format_ARGB32);

    for(int i=0;i<l;++i){
        for(int j=0;j<h;++j){
            im.setPixel(i,h-1-j,ptScreen(node,s,i,j,l,h));
        }
    }

    return im;
}

