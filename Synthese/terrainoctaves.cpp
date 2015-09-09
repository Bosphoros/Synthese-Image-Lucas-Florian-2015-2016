#include "terrainoctaves.h"
#include "smoothnoise.h"
#include <iostream>
TerrainOctaves::TerrainOctaves(QVector<Octave> &o):Terrain(),octaves(o)
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
    //TODO
    return 0;
}

float TerrainOctaves::getHauteurMax(QVector2D a,QVector2D b)
{
    //TODO
    return 0;
}

double TerrainOctaves::getPenteMax(QVector2D a,QVector2D b)
{
    //TODO
    return 0;
}
