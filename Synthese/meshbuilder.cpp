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

MeshBuilder::~MeshBuilder()
{

}
