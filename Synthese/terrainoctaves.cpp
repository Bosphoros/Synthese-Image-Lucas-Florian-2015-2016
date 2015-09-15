#include "terrainoctaves.h"
#include "smoothnoise.h"
#include <iostream>
TerrainOctaves::TerrainOctaves(QVector<Octave> &o, const Vector2D& aa, const Vector2D& bb):Terrain(aa,bb),octaves(o)
{
}

double TerrainOctaves::getHauteur(const Vector2D &p)
{
    double resu=0;
    int length= octaves.length();
    for(int i = 0; i <length; ++i)
    {
        resu+=octaves[i].getHauteur(p);
    }

    return resu;
}

double TerrainOctaves::getHauteurMin(Vector2D a, Vector2D b)
{
    double min=getHauteur(b);
    Vector2D vtmp;
    double tmp;
    for(int i=(int)a.y();i<b.y();i++){
        for(int j=(int)a.x();j<b.x();j++){
            vtmp=Vector2D(j,i);
            tmp=getHauteur(vtmp);
            if(min>tmp)
                min=tmp;
        }
    }
    return min;
}

double TerrainOctaves::getHauteurMax(Vector2D a,Vector2D b)
{
    double max=getHauteur(b);
    Vector2D vtmp;
    double tmp;
    for(int i=(int)a.y();i<b.y();i++){
        for(int j=(int)a.x();j<b.x();j++){
            vtmp=Vector2D(j,i);
            tmp=getHauteur(vtmp);
            if(max<tmp)
                max=tmp;
        }
    }
    return max;
}

double TerrainOctaves::getPenteMax(Vector2D a,Vector2D b)
{

    double max=0;
    Vector2D vtmp;
    Vector2D vtmp2;
    int tmp;
    double htmp;
    for(int i=(int)a.y();i<b.y();i++){
        for(int j=(int)a.x();j<b.x();j++){
            vtmp=Vector2D(j,i);
            vtmp2=Vector2D(j,i+1);
            htmp=getHauteur(vtmp);
            tmp=abs(htmp-getHauteur(vtmp2));
            if(max<tmp){
                max=tmp;
            }
            vtmp2=Vector2D(j+1,i);
            tmp=abs(htmp-getHauteur(vtmp2));
            if(max<tmp){
                max=tmp;
            }
        }
    }
    return max;
}
