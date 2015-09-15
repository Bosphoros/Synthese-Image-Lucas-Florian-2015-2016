#include "terrainimage.h"
#include "QColor"
#include <iostream>
#include <cmath>


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

double TerrainImage::getHauteur(const Vector2D &p)
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

double TerrainImage::getHauteurMax(Vector2D aa,Vector2D bb)
{

    Vector2D pTmpa=aa-a;
    pTmpa.setX(pTmpa.x()/(b.x()-a.x()));
    pTmpa.setY(pTmpa.y()/(b.y()-a.y()));

    Vector2D pTmpb=bb-a;
    pTmpb.setX(pTmpb.x()/(b.x()-a.x()));
    pTmpb.setY(pTmpb.y()/(b.y()-a.y()));

    int mini=pTmpa.y()<0?0:pTmpa.y()*h;
    int minj=pTmpa.x()<0?0:pTmpa.x()*w;
    int maxi=pTmpb.y()<1?pTmpb.y()*h:h-1;
    int maxj=pTmpb.x()<1?pTmpb.x()*w:w-1;

    quint8 max=0;
    for(int i=mini;i<=maxi;i++){
        for(int j=minj;j<=maxj;j++){
            if(max<mat[i*w+j]){
                max=mat[i*w+j];
            }
        }
    }
    return noir +(max*(blanc-noir)/255);
}

double TerrainImage::getHauteurMin(Vector2D aa,Vector2D bb)
{
    Vector2D pTmpa=aa-a;
    pTmpa.setX(pTmpa.x()/(b.x()-a.x()));
    pTmpa.setY(pTmpa.y()/(b.y()-a.y()));

    Vector2D pTmpb=bb-a;
    pTmpb.setX(pTmpb.x()/(b.x()-a.x()));
    pTmpb.setY(pTmpb.y()/(b.y()-a.y()));

    int mini=pTmpa.y()<0?0:pTmpa.y()*h;
    int minj=pTmpa.x()<0?0:pTmpa.x()*w;
    int maxi=pTmpb.y()<1?pTmpb.y()*h:h-1;
    int maxj=pTmpb.x()<1?pTmpb.x()*w:w-1;

    quint8 min=255;
    for(int i=mini;i<=maxi;i++){
        for(int j=minj;j<=maxj;j++){
            if(min>mat[i*w+j]){
                min=mat[i*w+j];
            }
        }
    }
    return noir +(min*(blanc-noir)/255);
}

double TerrainImage::getPenteMax(Vector2D a, Vector2D b)
{
    int mini=a.y()<0?0:a.y();
    int minj=a.x()<0?0:a.x();
    int maxi=b.y()<h?b.y():h-1;
    int maxj=b.x()<w?b.x():w-1;

    quint8 max=0;
    for(int i=mini;i<=maxi-1;i++){
        for(int j=minj;j<=maxj-1;j++){
            int tmp=abs((int)(mat[i*w+j])-(int)(mat[(i+1)*w+j]));
            if(max<tmp){
                max=tmp;
            }
            tmp=abs((int)(mat[i*w+j])-(int)(mat[i*w+j+1]));
            if(max<tmp){
                max=tmp;
            }
        }
    }
    return max;
}
