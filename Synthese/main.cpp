#include "terrainimage.h"
#include "meshbuilder.h"
#include <iostream>
int main(int argc, char *argv[])
{

    std::cout<<"coucou"<<std::endl;
    QString nm="D:/6Eclair1.jpg";
    QImage im;
    im.load(nm);
    QVector2D a(0,0);
    QVector2D b(100,100);
    TerrainImage t(im,(quint16)1000,(quint16)1000,a,b);
    MeshBuilder bu;
    QString nom="terrain";
    Mesh m =bu.terrain(t,a,b,100,nom);
    QString fichier="D:/terrain.obj";
    bu.saveMesh(fichier,m);
    return 0;
}
