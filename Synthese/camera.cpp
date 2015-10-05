#include "camera.h"
#include "ray.h"
#include <QColor>
#include <iostream>
#include <cmath>
#include "mathutils.h"
#include "smoothnoise.h"
#include <limits>

Camera::Camera(const Vector3D &o, const Vector3D &at, double d):origine(o),dw(d)
{
    Vector3D oat=(at-o);
    w=oat.normalized();
    u=-(w^Vector3D(0,1,0)).normalized();
    v= (w^u).normalized();
    lh=1;
    lw=16/9;
}
Vector3D mix(const Vector3D& a,const Vector3D& b, double d){
    double quadra=MathUtils::fonctionQuadratique(0,1,d);
    return b*quadra+a*(1-quadra);
}


QRgb Camera::ptScreen(Terrain * const t, const Vector3D& aBox, const Vector3D& bBox, const Vector3D& s, int i, int j, int l, int h,double pMax) const
{
    double x=i*2*lw/l-lw;
    double y=j*2*lh/h-lh;

    Vector3D pt =origine+(dw*w)+(x*u)+(y*v);
    Vector3D dir(pt-origine);
    dir.normalize();
    Ray r(origine,dir);

    Vector3D inter;
    bool isBox=false;
    //if(!t->intersectRayMarching(r,aBox,bBox,inter,isBox)){
    if(!t->intersectAdvanced(r,aBox,bBox,pMax,inter,isBox)){
        QColor couleur(255,255,255,0);
        return couleur.rgba();
    }

    Vector3D normale;
    t->getHauteurNormale(Vector2D(inter.x(),inter.z()),normale);
    if(isBox) {
        QColor couleur(0,0,0,255);
        return couleur.rgba();
    }
    Vector3D dirSoleil=(s-inter).normalized();
    double lu=normale*dirSoleil;


    if(lu<0)
        lu=0;

    lu*=200.0;

    if(lu>255)
        lu=255;
    Vector3D bas(74,97,77);
    Vector3D mil(91,75,55);
    Vector3D hau(234,234,234);
    Vector3D col;
    double intery=inter.y();
    intery+=-5+10*raw_noise_2d(inter.x()/20,inter.z()/20);
    if(intery<80){
        col=mix(bas,mil,intery/80);
    }
    else{
        col=mix(mil,hau,(intery-80)/20);
    }
    col*=((lu/255+0.4)/1.4);


    QColor couleur(col.x(),col.y(),col.z(),255);
    return couleur.rgba();


}

QImage Camera::printScreen(Terrain * const t, const Vector3D& s, int l, int h) const
{
    double pMax=t->getPenteMax();
    QImage im(l,h,QImage::Format_ARGB32);
    double min=t->getHauteurMin();
    double max=t->getHauteurMax();
    Vector3D aBox(t->getA().x(),min,t->getA().y());
    Vector3D bBox(t->getB().x(),max*1.5,t->getB().y());

    #pragma omp parallel for
    for(int i=0;i<l;++i){
        for(int j=0;j<h;++j){
            im.setPixel(l-1-i,h-1-j,ptScreen(t,aBox,bBox,s,i,j,l,h,pMax));
        }
    }

    return im;

}


void Camera::translate(const Vector3D &v)
{
    origine+=v;
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
    QVector<Vector3D> normals;
    if(!t.intersect(r,intersects, normals)){
        QColor couleur(0,0,0,0);
        return couleur.rgba();
    }

         double d=std::numeric_limits<double>::infinity();
         Vector3D norm;

         for(int i=0;i<intersects.size();++i){
             if(d>intersects.at(i)&&intersects.at(i)>0)
             {
                 d=intersects.at(i);
                norm = normals.at(i);
             }
         }

         if (d==std::numeric_limits<double>::infinity()){
             QColor couleur(0,0,0,0);
             return couleur.rgba();
         }


         Vector3D inter=r.getPoint(d);

         Vector3D dirSoleil=(s-inter).normalized();
         double lu=norm*dirSoleil;


         if(lu<0)
             lu=0;

         lu*=255.0;


         /*d*=d*d*d*d;
            if(d>20)
                d=20;
          QColor couleur(0,255*(1-d/20),0,255);
          return couleur.rgba();*/
         return QColor(lu, lu, lu, 255).rgba();

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

