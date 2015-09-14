#include "terrainimage.h"
#include "QColor"
#include <iostream>
#include <cmath>


TerrainImage::TerrainImage(QImage& i, bool blanc,const QVector2D& a,const QVector2D& b):Terrain(a,b)
{

    h=i.height();
    w=i.width();
    for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            QRgb p=i.pixel(k,j);
            quint8 c=(quint8)qGray(p);
            if(!blanc)
                c=255-c;
            mat.push_back(c);
        }
    }
}

float TerrainImage::getHauteur(const QVector2D &p)
{
    QVector2D pTmp=p-a;
    pTmp.setX(pTmp.x()/(b.x()-a.x()));
    pTmp.setY(pTmp.y()/(b.y()-a.y()));
    float u=pTmp.x();
    float v=pTmp.y();
    float rx = (u*(w-1));
    float ry=(v*(h-1));
    int i =(int) rx;
    rx-=i;
    int j = (int) ry;
    ry -= j;

    if(i<0||j<0||i>w-1||j>h-1){
        return 0;
    }

    //std::cout << pTmp.x() << "/" << pTmp.y() << std::endl;
    //std::cout << u << "/" << v << " " << rx << "/" << ry << std::endl;
    //float rx= resteI; //(p.x()-a.x())*w/(b.x()-a.x())-i;
    //float ry= resteJ;//(p.y()-a.y())*h/(b.y()-a.y())-j;

    quint16 z=(1-rx)*(1-ry)*mat[j*w+i]+
                rx*(1-ry)*mat[j*w+i+1]+
                (1-rx)*ry*mat[(j+1)*w+i]+
                rx*ry*mat[(j+1)*w+i+1];

    return z;
}

float TerrainImage::getHauteurMax(QVector2D a,QVector2D b)
{
    int mini=a.y()<0?0:a.y();
    int minj=a.x()<0?0:a.x();
    int maxi=b.y()<h?b.y():h-1;
    int maxj=b.x()<w?b.x():w-1;

    quint8 max=0;
    for(int i=mini;i<=maxi;i++){
        for(int j=minj;j<=maxj;j++){
            if(max<mat[i*w+j]){
                max=mat[i*w+j];
            }
        }
    }
    return max;
}

float TerrainImage::getHauteurMin(QVector2D a,QVector2D b)
{
    int mini=0;
    int minj=0;
    int maxi=h-1;
    int maxj=w-1;

    quint8 min=255;
    for(int i=mini;i<=maxi;i++){
        for(int j=minj;j<=maxj;j++){
            if(min>mat[i*w+j]){
                min=mat[i*w+j];
            }
        }
    }
    return min;
}

double TerrainImage::getPenteMax(QVector2D a, QVector2D b)
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
