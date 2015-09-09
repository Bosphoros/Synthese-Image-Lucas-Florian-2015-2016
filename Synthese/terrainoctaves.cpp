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

float TerrainOctaves::getHauteurMin()
{
    //TODO
    return 0;
}

float TerrainOctaves::getHauteurMax()
{
    //TODO
    return 0;
}

double TerrainOctaves::getPenteMax()
{
    //TODO
    return 0;
}
