#include "terrainimage.h"
#include "QColor"
#include <iostream>


TerrainImage::TerrainImage(QImage& i, bool b):Terrain(),blanc(b)
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

float TerrainImage::getHauteur(const QVector2D &p)
{
    QVector2D pTmp;
    pTmp.setX(p.x());
    pTmp.setY(p.y());
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

    if(!blanc)
        z=255-z;
    return z;
}

float TerrainImage::getHauteurMin(QVector2D a,QVector2D b)
{
    //TODO
    return 0;
}

float TerrainImage::getHauteurMax(QVector2D a,QVector2D b)
{
    //TODO
    return 0;
}

double TerrainImage::getPenteMax(QVector2D a, QVector2D b)
{
    //TODO
    return 0;
}
