#include "terrainimage.h"
#include "QColor"
#include <iostream>
#include <cmath>
#ifndef fmin
    #define fmin(a,b) a<b?a:b
#endif
#ifndef fmax
    #define fmax(a,b) a>b?a:b
#endif

TerrainImage::TerrainImage(QImage& i, double bl, double no, const Vector2D& a, const Vector2D& b):Terrain(a,b), blanc(bl), noir(no)
{

    h=i.height();
    w=i.width();
    for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            QRgb p=i.pixel(k,j);
            quint8 c=(quint8)qGray(p);
            mat.push_back(c);
        }
    }
}

double TerrainImage::getHauteur(const Vector2D &p) const
{
    Vector2D pTmp=p-a;
    pTmp.setX(pTmp.x()/(b.x()-a.x()));
    pTmp.setY(pTmp.y()/(b.y()-a.y()));
    double u=pTmp.x();
    double v=pTmp.y();
    double rx = (u*(w-1));
    double ry=(v*(h-1));
    int i =(int) rx;
    rx-=i;
    int j = (int) ry;
    ry -= j;

    if(i<0||j<0||i>w-1||j>h-1){
        return 0;
    }

    //std::cout << pTmp.x() << "/" << pTmp.y() << std::endl;
    //std::cout << u << "/" << v << " " << rx << "/" << ry << std::endl;
    //double rx= resteI; //(p.x()-a.x())*w/(b.x()-a.x())-i;
    //double ry= resteJ;//(p.y()-a.y())*h/(b.y()-a.y())-j;

    quint16 z=(1-rx)*(1-ry)*mat[j*w+i]+
                rx*(1-ry)*mat[j*w+i+1]+
                (1-rx)*ry*mat[(j+1)*w+i]+
                rx*ry*mat[(j+1)*w+i+1];

    return noir +(z*(blanc-noir)/255);;
}

double TerrainImage::getHauteurMax() const
{
    return fmax(blanc,noir);
}

double TerrainImage::getHauteurMin() const
{
    return fmin(blanc,noir);
}

double TerrainImage::getPenteMax() const
{

    double pasx=(b.x()-a.x())/w;
    double pasy=(b.y()-a.y())/h;
    double max=0;
    for(int i=0;i<h-1;i++){
        for(int j=0;j<=w-1;j++){
            int tmp=abs((int)(mat[i*w+j])-(int)(mat[(i+1)*w+j]))/pasy;
            if(max<tmp){
                max=tmp;
            }
            tmp=abs((int)(mat[i*w+j])-(int)(mat[i*w+j+1]))/pasx;
            if(max<tmp){
                max=tmp;
            }
        }
    }
    return max;
}
