#include "terrainimage.h"
#include "QColor"
#include <iostream>


TerrainImage::TerrainImage(QImage& i, quint16 lo, quint16 la, QVector2D &aa, QVector2D &bb):longueur(lo),largeur(la)
{
    a=aa;
    b=bb;
    h=i.height();
    w=i.width();
    std::cout<<"coucou"<<std::endl;
    for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            QRgb p=i.pixel(k,j);
            quint8 c=(quint8)qGray(p);
            mat.push_back(c);
            std::cout<<c<<std::endl;
        }
    }
}

quint16 TerrainImage::getHauteur(QVector2D &p)
{
    float u=(p.x()-a.x())/(b.x()-a.x());
    float v=(p.y()-a.y())/(b.y()-a.y());

    int i=(int)(u*(w-1));
    int j=(int)(v*(h-1));

    if(i<0||j<0||i>w-1||j>h-1){
        return 0;
    }

    float rx=(p.x()-a.x())*w/(b.x()-a.x())-i;
    float ry=(p.y()-a.y())*h/(b.y()-a.y())-j;

    quint16 z=(1-rx)*(1-ry)*mat[j*w+i]+
                rx*(1-ry)*mat[j*w+i+1]+
                (1-rx)*ry*mat[(j+1)*w+i]+
                rx*ry*mat[(j+1)*w+i+1];

    return z;
}

quint16 TerrainImage::getHauteurMin()
{
    //TODO
    return 0;
}

quint16 TerrainImage::getHauteurMax()
{
    //TODO
    return 0;
}

double TerrainImage::getPenteMax()
{
    //TODO
    return 0;
}
