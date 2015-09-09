#include "terrainimage.h"
#include "meshbuilder.h"
#include <iostream>
#include "terrainoctaves.h"
int main(int argc, char *argv[])
{
    //QString nm="D:/Marilyn2.jpg";
    //QImage im;
    //im.load(nm);
    QVector2D a(0,0);
    QVector2D b(90000,90000);
    //TerrainImage t(im,(quint16)1000,(quint16)1000,a,b);
    FoncteurWarp w;
    Noise n(15641);
    Noise n2(0);
    Octave o(0.2,20000,15000,1000,0.05,w,w,n,n2);
    Octave o2(0.1,5000,50000,20,0.01,w,w,n2,n);
    Octave o3(0.05,2500,50000,5,0.005,w,w,n2,n);
    QVector<Octave> os;
    os.push_back(o);
    os.push_back(o2);
    TerrainOctaves t(os);
    MeshBuilder bu;
    QString nom="terrain";
    Mesh m =bu.terrain(t,a,b,300,nom);
    QString fichier="D:/terrain.obj";
    bu.saveMesh(fichier,m);
    return 0;
}
