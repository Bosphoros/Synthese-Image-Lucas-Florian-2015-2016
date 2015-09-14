#include "terrainoctaves.h"
#include "smoothnoise.h"
#include <iostream>
TerrainOctaves::TerrainOctaves(QVector<Octave> &o, const QVector2D& aa, const QVector2D& bb):Terrain(aa,bb),octaves(o)
{
}

float TerrainOctaves::getHauteur(const QVector2D &p)
{
    float resu=0;
    int length= octaves.length();
    for(int i = 0; i <length; ++i)
    {
        resu+=octaves[i].getHauteur(p);
    }

    return resu;
}

float TerrainOctaves::getHauteurMin(QVector2D a, QVector2D b)
{
    float min=getHauteur(b);
    QVector2D vtmp;
    float tmp;
    for(int i=(int)a.y();i<b.y();i++){
        for(int j=(int)a.x();j<b.x();j++){
            vtmp=QVector2D(j,i);
            tmp=getHauteur(vtmp);
            if(min>tmp)
                min=tmp;
        }
    }
    return min;
}

float TerrainOctaves::getHauteurMax(QVector2D a,QVector2D b)
{
    float max=getHauteur(b);
    QVector2D vtmp;
    float tmp;
    for(int i=(int)a.y();i<b.y();i++){
        for(int j=(int)a.x();j<b.x();j++){
            vtmp=QVector2D(j,i);
            tmp=getHauteur(vtmp);
            if(max<tmp)
                max=tmp;
        }
    }
    return max;
}

double TerrainOctaves::getPenteMax(QVector2D a,QVector2D b)
{

    float max=0;
    QVector2D vtmp;
    QVector2D vtmp2;
    int tmp;
    float htmp;
    for(int i=(int)a.y();i<b.y();i++){
        for(int j=(int)a.x();j<b.x();j++){
            vtmp=QVector2D(j,i);
            vtmp2=QVector2D(j,i+1);
            htmp=getHauteur(vtmp);
            tmp=abs(htmp-getHauteur(vtmp2));
            if(max<tmp){
                max=tmp;
            }
            vtmp2=QVector2D(j+1,i);
            tmp=abs(htmp-getHauteur(vtmp2));
            if(max<tmp){
                max=tmp;
            }
        }
    }
    return max;
}
