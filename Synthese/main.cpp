#include "terrainimage.h"
#include "meshbuilder.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QString nm="D:/heightmap.png";
    QImage im;
    im.load(nm);
    QVector2D a(0,0);
    QVector2D b(1000,1000);
    TerrainImage t(im,(quint16)1000,(quint16)1000,a,b);
    MeshBuilder bu;
    QString nom="terrain";
    Mesh m =bu.terrain(t,a,b,500,nom);
    QString fichier="D:/terrain.obj";
    bu.saveMesh(fichier,m);
    return 0;
}