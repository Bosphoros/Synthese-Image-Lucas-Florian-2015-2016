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
    for(QList<QVector3D>::iterator itVect = mesh.getGeom().begin(); itVect != mesh.getGeom().end(); ++itVect) {
    out << "v " << itVect->x() << " " << itVect->y() << " " << itVect->z() << "\n";
    }
    out << "\n";

    cout<<"geom ok"<<endl;

    for(QList<QVector3D>::iterator itNorm = mesh.getNorm().begin(); itNorm != mesh.getNorm().end(); ++itNorm) {
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

Mesh MeshBuilder::terrain(Terrain &t, QVector2D &a, QVector2D &b, int e,QString nom){
    QVector2D aa,bb;
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
    b=bb;
    QList<QVector3D> geom;
    QList<QVector3D> norm;
    QList<int> topo;

    QVector2D dif=b-a;

    for(int i=0;i<e;i++){
        for(int j=0;j<e;j++){
            QVector2D p;
            p.setX(a.x()+dif.x()*((float)i/e));
            p.setY(a.y()+dif.y()*((float)j/e));
            QVector3D n;
            QVector2D ptemp(p.x()/dif.x(),p.y()/dif.y());
            double h=t.getHauteurNormale(ptemp,n);

            geom.append(QVector3D(p.x(),(float)h,p.y()));
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

MeshBuilder::~MeshBuilder()
{

}
