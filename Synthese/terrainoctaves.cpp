#include "terrainoctaves.h"
#include "smoothnoise.h"
#include <iostream>
TerrainOctaves::TerrainOctaves(QVector<Octave> &o):octaves(o)
{
}

quint16 TerrainOctaves::getHauteur(const QVector2D &p)
{
    quint16 resu=0;
    int length= octaves.length();
    for(int i = 0; i <length; ++i)
    {
        resu+=octaves[i].getHauteur(p);
    }

    return resu;
}

quint16 TerrainOctaves::getHauteurMin()
{
    //TODO
    return 0;
}

quint16 TerrainOctaves::getHauteurMax()
{
    //TODO
    return 0;
}

double TerrainOctaves::getPenteMax()
{
    //TODO
    return 0;
}
