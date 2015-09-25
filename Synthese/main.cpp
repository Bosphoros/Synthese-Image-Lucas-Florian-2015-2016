#include "terrainimage.h"
#include <iostream>
#include "terrainpentex.h"
#include "ray.h"
#include <QTime>
#include "camera.h"
#include "terrainnoisesmultiples.h"
#include <vector>
#include "meshbuilder.h"
#define M_PI 3.14159265358979323846
int main(int argc, char *argv[])
{

    Vector2D a(0,0);
    Vector2D b(1000,1000);

    /*QString nm="C:/Users/etu/Desktop/Heightmap.png";
    QImage im;
    im.load(nm);
    TerrainImage t(im,0,300,a,b);//*/
    TerrainPenteX t(a,b);
    /*std::vector<double> ampl;
    ampl.push_back(200);
    ampl.push_back(100);
    ampl.push_back(10);
    ampl.push_back(20);
    std::vector<double> freq;
    freq.push_back(500);
    freq.push_back(250);
    freq.push_back(80);
    freq.push_back(200);
    TerrainNoisesMultiples t(0,freq,ampl,a,b);//0,100,100

    /*FoncteurWarp w;
    Noise n(15641);
    Noise n2(0);
    Octave o1(0.2,200,150,1000,0.05,w,w,n,n2);
    Octave o2(0.1,50,500,20,0.01,w,w,n2,n);
    Octave o3(0.05,25,500,5,0.005,w,w,n2,n);
    QVector<Octave> os;
    os.push_back(o1);
    //os.push_back(o2);
    TerrainOctaves t(os,a,b);//*/

    /*MeshBuilder bu;
    QString nom="terrain";
    Mesh m =bu.terrain(t,300,nom);
    QString fichier="D:/terrain.obj";
    bu.saveMesh(fichier,m);//*/

    Vector3D o(-3400, 2800, -2200);
    Vector3D d(1,-1,1);

    Vector3D soleil(100000000,0,0);
   /* QMatrix3x3 mat1;
        mat1(0,0)=cos(M_PI/4);
        mat1(0,1)=-sin(M_PI/4);
        mat1(0,2)=0;
        mat1(1,0)=sin(M_PI/4);
        mat1(1,1)=cos(M_PI/4);
        mat1(1,2)=0;
        mat1(2,0)=0;
        mat1(2,1)=0;
        mat1(2,2)=1;
        soleil.rotate(mat1);*/

    Ray r(o, d);
    /*Vector3D a(-3,-3,0);
    Vector3D b(3, 3, 5);
    Vector3D c(1.62,1.24,3);*/
    /*Vector3D resu;
    Vector3D resuIn;
    Vector3D resuOut;
    /*bool i = r.intersects(a,b,c,resu);
    int j = r.intersectsBox(a,b,resuIn, resuOut);
    //std::cout << i << " " << resu.x() << ", " << resu.y() << ", " << resu.z() << std::endl;
    std::cout << j << " " << resuIn.x() << ", " << resuIn.y() << ", " << resuIn.z() << std::endl << " out " << resuOut.x() << ", " << resuOut.y() << ", " << resuOut.z();*/

    double min = t.getHauteurMin();
    double max = t.getHauteurMax();
    Vector3D aBox(a.x(), min, a.y());
    Vector3D bBox(b.x(), max, b.y());
    /*QTime time;
    time.start();
    for(int i = 0; i < 1000; ++i) {
        r.intersectRayMarching(t,aBox,bBox,resu);
        //std::cout << time.restart() << std::endl;
    }
    std::cout << time.restart() << std::endl;*/
    //std::cout << touche << " en " << resu.x() << ", " << resu.y() << ", " << resu.z() << std::endl;


    Vector3D dirCam(500,0,500);
    Vector3D dist(o+d);
    std::cout << o.distanceToPoint(dist) << std::endl;
    Camera cam(o, dirCam, o.distanceToPoint(dist)*4);//o.distanceToPoint(dirCam));
    QImage result = cam.printScreen(&t,soleil,192*10,108*10);
    QString nameImage = "D:/result4.png";
    result.save(nameImage);//*/

    int nbShoot=10;
    QMatrix3x3 mat;
        mat(0,0)=cos(M_PI/nbShoot);
        mat(0,1)=-sin(M_PI/nbShoot);
        mat(0,2)=0;
        mat(1,0)=sin(M_PI/nbShoot);
        mat(1,1)=cos(M_PI/nbShoot);
        mat(1,2)=0;
        mat(2,0)=0;
        mat(2,1)=0;
        mat(2,2)=1;


    for(int i=0; i<nbShoot;++i){
        soleil.rotate(mat);
        QImage result = cam.printScreen(&t,soleil,192*10,108*10);
        std::string str="D:/1shoot/result"+ std::to_string (i)+".png";
        QString nameImage(str.c_str());
        result.save(nameImage);//
        std::cerr<<"\r"<<100.0*(i+1)/nbShoot<<"%";
    }

    return 0;
}
