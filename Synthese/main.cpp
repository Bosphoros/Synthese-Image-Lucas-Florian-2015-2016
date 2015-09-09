#include "terrainimage.h"
#include "meshbuilder.h"
#include <iostream>
#include "terrainoctaves.h"
#include "ray.h"
int main(int argc, char *argv[])
{
    QString nm="D:/terrainPlat.png";
    QImage im;
    im.load(nm);
    QVector2D a(0,0);
    QVector2D b(1000,1000);
    TerrainImage t(im,false);
    /*FoncteurWarp w;
    Noise n(15641);
    Noise n2(0);
    Octave o(0.2,200,150,1000,0.05,w,w,n,n2);
    Octave o2(0.1,50,500,20,0.01,w,w,n2,n);
    Octave o3(0.05,25,500,5,0.005,w,w,n2,n);
    QVector<Octave> os;
    os.push_back(o);
    os.push_back(o2);
    TerrainOctaves t(os);*/
    /*MeshBuilder bu;
    QString nom="terrain";
    Mesh m =bu.terrain(t,a,b,300,nom,0.01);
    QString fichier="D:/terrain.obj";
    bu.saveMesh(fichier,m);*/
    QVector3D o(800, 500, 980);
    QVector3D d(0,-1,0);
    Ray r(o, d);
    /*QVector3D a(-3,-3,0);
    QVector3D b(3, 3, 5);
    QVector3D c(1.62,1.24,3);*/
    QVector3D resu;
    //QVector3D resuIn;
    //QVector3D resuOut;
    /*bool i = r.intersects(a,b,c,resu);
    int j = r.intersectsBox(a,b,resuIn, resuOut);
    //std::cout << i << " " << resu.x() << ", " << resu.y() << ", " << resu.z() << std::endl;
    std::cout << j << " " << resuIn.x() << ", " << resuIn.y() << ", " << resuIn.z() << std::endl << " out " << resuOut.x() << ", " << resuOut.y() << ", " << resuOut.z();*/

    bool touche = r.intersectRayMarching(t,a,b,resu);

    //std::cout << touche << " en " << resu.x() << ", " << resu.y() << ", " << resu.z() << std::endl;


    return 0;
}
