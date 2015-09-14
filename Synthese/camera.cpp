#include "camera.h"
#include "ray.h"
#include <QColor>
#include <iostream>
#include <cmath>

Camera::Camera(QVector3D &o, QVector3D &at):origine(o)
{
    QVector3D oat=(at-o);
    w=oat.normalized();
    dw=oat.length();
    u=-(QVector3D::crossProduct(w,QVector3D(0,1,0))).normalized();
    v= QVector3D::crossProduct(w,u).normalized();
    lh=1;
    lw=16/9;


}

QRgb Camera::ptScreen(Terrain &t,const QVector3D& aBox, const QVector3D& bBox, const QVector3D& s, int i, int j, int l, int h)
{
    double x=i*2*lw/l-lw;
    double y=j*2*lh/h-lh;

    QVector3D pt =origine+(dw*w)+(x*u)+(y*v);
    QVector3D dir(pt-origine);
    dir.normalize();
    Ray r(origine,dir);

    //std::cout << origine.x()  <<", "<<origine.y()<<", "<<origine.z()<<"/"<<dir.x()<<", "<<dir.y()<<", "<<dir.z()<< std::endl;
    QVector3D inter;
    bool isBox=false;
    if(!r.intersectRayMarching(t,aBox,bBox,inter,isBox)){
        QColor couleur(0,0,255,255);
        return couleur.rgb();
    }

    //std::cout << "Touch" << std::endl;
    QVector3D normale;
    float hauteur = t.getHauteurNormale(QVector2D(inter.x(),inter.z()),normale);
    if(isBox) {
        QColor couleur(255,0,0,255);
        return couleur.rgb();
    }
    //std::cout << normale.x()  <<", "<<normale.y()<<", "<<normale.z()<<std::endl;
    double lu=QVector3D::dotProduct(normale,-s);
    //std::cout <<lu<<std::endl;
    if(lu<0)
        lu=0;


    lu*=200.0;

    if(lu>255)
        lu=255;

    QColor couleur(lu,lu,lu,255);
    return couleur.rgb();


}

QImage Camera::printScreen(Terrain &t,const QVector2D& a, const QVector2D& b, const QVector3D& s, int l, int h)
{
    QImage im(l,h,QImage::Format_ARGB32);
    double min=t.getHauteurMin(a,b);
    double max=t.getHauteurMax(a,b);
    QVector3D aBox(a.x(),min,a.y());
    QVector3D bBox(b.x(),max*1.01,b.y());

    for(int i=0;i<l;++i){
        for(int j=0;j<h;++j){
            im.setPixel(i,h-1-j,ptScreen(t,aBox,bBox,s,i,j,l,h));
        }
    }

    return im;

}

