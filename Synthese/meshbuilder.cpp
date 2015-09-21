#include "meshbuilder.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <cmath>
#ifndef fmin
#define fmin(a,b) a<b?a:b
#endif
#define PI 3.14159265358979323846
using namespace std;
MeshBuilder::MeshBuilder()
{
}

void MeshBuilder::saveMesh(QString &nom, Mesh& mesh)
{
    QFile file(nom);
    cout<<"fichier créé"<<endl;
    file.open((QIODevice::WriteOnly | QIODevice::Text));
    cout<<"fichier ouvert"<<endl;
    QTextStream out(&file);
    cout<<"flux créé"<<endl;
    out << "o "<<mesh.getNom()<<"\n";
    for(QList<Vector3D>::iterator itVect = mesh.getGeom().begin(); itVect != mesh.getGeom().end(); ++itVect) {
    out << "v " << itVect->x() << " " << itVect->y() << " " << itVect->z() << "\n";
    }
    out << "\n";

    cout<<"geom ok"<<endl;

    for(QList<Vector3D>::iterator itNorm = mesh.getNorm().begin(); itNorm != mesh.getNorm().end(); ++itNorm) {
    out << "vn " << itNorm->x() << " " << itNorm->y() << " " << itNorm->z() << "\n";
    }
    out << "\n";

    out << "vt 0.0 0.0 \n\n";

    for(QList<int>::iterator it = mesh.getTopo().begin(); it != mesh.getTopo().end();) {
    out << "f ";
    for(int i = 0; i < 3; i++) {
    int face = (*(it++)) + 1;
    int texture = (*(it++)) + 1;
    int normale = (*(it++)) + 1;
    out << face << "/" << texture << "/" << normale << " ";
    }
    out << "\n";
    }

    file.close();
    cout<<"fichier fermé"<<endl;
}

Mesh MeshBuilder::terrain(Terrain &t, int e, QString nom){
   /* Vector2D aa,bb;
    if(a.x()<b.x()){
         aa.setX(a.x());
         bb.setX(b.x());
    }
    else{
        aa.setX(b.x());
        bb.setX(a.x());
    }

    if(a.y()<b.y()){
         aa.setY(a.y());
         bb.setY(b.y());
    }
    else{
        aa.setY(b.y());
        bb.setY(a.y());
    }

    a=aa;
    b=bb;*/
    QList<Vector3D> geom;
    QList<Vector3D> norm;
    QList<int> topo;

    Vector2D a=t.getA();
    Vector2D b=t.getB();

    Vector2D dif=b-a;

    for(int i=0;i<e;i++){
        for(int j=0;j<e;j++){
            Vector2D p;
            p.setX(a.x()+dif.x()*((double)i/e));
            p.setY(a.y()+dif.y()*((double)j/e));
            Vector3D n;
            //Vector2D ptemp(p.x(),p.y());
            double h=t.getHauteurNormale(p,n);

            geom.append(Vector3D(p.x(),h,p.y()));
            norm.append(n);
            if(i<e-1&&j<e-1){
                topo.append(e*j+i);
                topo.append(0);
                topo.append(e*j+i);
                topo.append(e*j+i+1);
                topo.append(0);
                topo.append(e*j+i+1);
                topo.append(e*(j+1)+i+1);
                topo.append(0);
                topo.append(e*(j+1)+i+1);


                topo.append(e*j+i);
                topo.append(0);
                topo.append(e*j+i);
                topo.append(e*(j+1)+i+1);
                topo.append(0);
                topo.append(e*(j+1)+i+1);
                topo.append(e*(j+1)+i);
                topo.append(0);
                topo.append(e*(j+1)+i);

            }
        }

    }

    return Mesh(geom,topo,norm,nom);
}
// Ne prend pas les textures en compte
Mesh MeshBuilder::loadMesh(QString &nom)
{
    QList<Vector3D> geoms;
    QList<Vector3D> norms;
    QList<int> topos;
    QFile file(nom);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString read;

    while(true) {
        read = in.readLine();
        QStringList l = read.split(" ");
        if(l.at(0) == "v") {
            Vector3D tmp(l.at(1).toDouble(), l.at(2).toDouble(), l.at(3).toDouble());
            geoms.append(tmp);
        }
        if(l.at(0) == "vn") {
            Vector3D tmp(l.at(1).toDouble(), l.at(2).toDouble(), l.at(3).toDouble());
            norms.append(tmp);
        }
        if(l.at(0) == "f") {
            for(int i = 1; i < 4; ++i){
                QStringList l2 = l.at(i).split("/");
                for(int j = 0; j < l2.length(); ++j) {
                    topos.append(l2.at(j).toInt()-1);
                }
            }
        }
        if(in.atEnd()) {
            break;
        }
    }

    Mesh res(geoms, topos, norms, nom);
    std::cout << nom.toStdString() << " chargé" << std::endl;
    return res;
}

MeshBuilder::~MeshBuilder()
{

}
