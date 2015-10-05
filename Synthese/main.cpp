#include "terrainimage.h"
#include <iostream>
#include "terraintest.h"
#include "ray.h"
#include <QTime>
#include "camera.h"
#include "terrainnoisesmultiples.h"
#include <vector>
#include "meshbuilder.h"
#include "csgsphere.h"
#include "csgunion.h"
#include "csgintersection.h"
#include "csgdifference.h"
#include "csgbox.h"
#include "tableauvoxel.h"
#define M_PI 3.14159265358979323846
Terrain* generationImage(const QString& img){
    Vector2D a(0,0);
    Vector2D b(1000,1000);
    QImage im;
    im.load(img);
    return new TerrainImage(im,200,0,a,b);
}


Terrain* generationProcedural(){
    Vector2D a(0,0);
    Vector2D b(1000,1000);
    return new TerrainTest(a,b);
}


void shoot(Terrain* const t, const QString& img){
    Vector3D o(-3400, 2800, -2200);
    Vector3D d(1,-1,1);

    Vector3D soleil(100000000,0,0);
    QMatrix3x3 mat1;
    mat1(0,0)=cos(3*M_PI/4);
    mat1(0,1)=-sin(3*M_PI/4);
    mat1(0,2)=0;
    mat1(1,0)=sin(3*M_PI/4);
    mat1(1,1)=cos(3*M_PI/4);
    mat1(1,2)=0;
    mat1(2,0)=0;
    mat1(2,1)=0;
    mat1(2,2)=1;
    soleil.rotate(mat1);

    Vector3D dirCam(500,0,500);
    Vector3D dist(o+d);
    Camera cam(o, dirCam, o.distanceToPoint(dist)*4);
    QImage result = cam.printScreen(t,soleil,192*10,108*10);
    result.save(img);
}

void shootMulti(Terrain* const t, const QString& img, int nbShoot){
    Vector3D o(-3400, 2800, -2200);

    Vector3D soleil(100000000,0,0);

    Vector3D dirCam(500,0,500);

    QMatrix3x3 mat;
        mat(0,0)=cos(2*M_PI/nbShoot);
        mat(0,1)=-sin(2*M_PI/nbShoot);
        mat(0,2)=0;
        mat(1,0)=sin(2*M_PI/nbShoot);
        mat(1,1)=cos(2*M_PI/nbShoot);
        mat(1,2)=0;
        mat(2,0)=0;
        mat(2,1)=0;
        mat(2,2)=1;

    QMatrix3x3 matcam;
        matcam(0,0)=cos(2*M_PI/nbShoot);
        matcam(0,1)=0;
        matcam(0,2)=sin(2*M_PI/nbShoot);
        matcam(1,0)=0;
        matcam(1,1)=1;
        matcam(1,2)=0;
        matcam(2,0)=-sin(2*M_PI/nbShoot);
        matcam(2,1)=0;
        matcam(2,2)=cos(2*M_PI/nbShoot);


    for(int i=0; i<nbShoot;++i){
        Camera cam(o, dirCam, 6.92820);
        soleil.rotate(mat);
        o.rotate(matcam);
        QImage result = cam.printScreen(t,soleil,192*10,108*10);
        QString nameImage =img;
        nameImage+=std::to_string(i).c_str();
        nameImage+=".png";
        result.save(nameImage);
        std::cerr<<"\r"<<100.0*(i+1)/nbShoot<<"%";
    }
}

void generateMesh(Terrain* const t,const QString& obj,int echantillion){

    MeshBuilder bu;
    QString nom="terrain";
    Mesh m =bu.terrain(*t,echantillion,nom);
    bu.saveMesh(obj,m);

}

int main(int argc, char *argv[])
{
    int arg=1;
    QTime time;

   /* time.restart();
    QString img=argv[arg++];
    Terrain* t=generationImage(img);
    std::cout << "Terrain from image generated : " << time.restart() << "ms." << std::endl;//*/

     /* time.restart();
      Terrain* t=generationProcedural();
      std::cout << "Terrain generated : " << time.restart() << "ms." << std::endl;
     //*/


    /*time.restart();
    QString obj=argv[arg++];
    generateMesh(t,obj,300);
    std::cout << "Mesh generated : " << time.restart() << "ms." << std::endl;//*/

    /*time.restart();
    QString destination=argv[arg++];
    shoot(t,destination);
    std::cout << "Image generated from ray launching : " << time.restart() << "ms." << std::endl;//*/

   /* time.restart();
    QString destination=argv[arg++];

    shootMulti(t,destination,100);
    std::cout << "100 images generated from ray launching : " << time.restart() << "ms." << std::endl;//*/

    //delete t;

    /*
    Vector3D centre(1.0f,0.0f,0.0f);
    Vector3D centre2(0.0f,.5f,0.0f);

    Vector3D origine(-3.0f,0.0f,0.0f);
    Vector3D direction(1.0f,0.0f,0.0f);

    Vector3D soleil(-10000.0f,0.0f,0.0f);

    CSGSphere sphere(centre, 1.0f);
    CSGSphere sphere2(centre2, 0.75f);
    CSGBox box(Vector3D(-1,-0.5,-1), Vector3D(1,-0.25,1));


    CSGDifference dif(&sphere, &sphere2);

    CSGUnion union2(&dif, &box);

    Camera cam(origine, direction,1.0);

    QImage result = cam.printScreen(box, soleil, 900, 900);

    QString nameImage = "C:/Users/etu/Desktop/sphereTest.png";
    result.save(nameImage);*/

   MeshBuilder mb;
    TableauVoxel tab(3,3,3,10);
    tab(0,0,0)=1;
    tab(0,1,0)=1;
    tab(0,1,1)=1;
    tab(0,1,2)=1;
    QString nameImage = "C:/Users/etu/Desktop/voxel.obj";
    Mesh m=mb.voxel(tab,nameImage);
    mb.saveMesh(nameImage,m);

    return 0;
}
