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

Mesh MeshBuilder::box(const Box &box, const QString& nom) const
{
    Vector3D a = box.getA();
    Vector3D b = box.getB();

    QList<Vector3D> v;
    QList<Vector3D> vn;
    QList<int> t;

    float ax=a.x();
    float bx=b.x();
    float ay=a.y();
    float by=b.y();
    float az=a.z();
    float bz=b.z();

    v.append(a);
    v.append(Vector3D(bx,ay,az));
    v.append(Vector3D(ax,by,az));
    v.append(Vector3D(bx,by,az));
    v.append(Vector3D(ax,ay,bz));
    v.append(Vector3D(bx,ay,bz));
    v.append(Vector3D(ax,by,bz));
    v.append(b);

    vn.append(Vector3D(1.0,0.0,0.0));
    vn.append(Vector3D(-1.0,0.0,0.0));
    vn.append(Vector3D(0.0,1.0,0.0));
    vn.append(Vector3D(0.0,-1.0,0.0));
    vn.append(Vector3D(0.0,0.0,1.0));
    vn.append(Vector3D(0.0,0.0,-1.0));

    t.append(1);
    t.append(0);
    t.append(0);
    t.append(3);
    t.append(0);
    t.append(0);
    t.append(7);
    t.append(0);
    t.append(0);

    t.append(1);
    t.append(0);
    t.append(0);
    t.append(7);
    t.append(0);
    t.append(0);
    t.append(5);
    t.append(0);
    t.append(0);

    t.append(2);
    t.append(0);
    t.append(1);
    t.append(0);
    t.append(0);
    t.append(1);
    t.append(4);
    t.append(0);
    t.append(1);

    t.append(2);
    t.append(0);
    t.append(1);
    t.append(4);
    t.append(0);
    t.append(1);
    t.append(6);
    t.append(0);
    t.append(1);

    t.append(3);
    t.append(0);
    t.append(2);
    t.append(2);
    t.append(0);
    t.append(2);
    t.append(6);
    t.append(0);
    t.append(2);

    t.append(3);
    t.append(0);
    t.append(2);
    t.append(6);
    t.append(0);
    t.append(2);
    t.append(7);
    t.append(0);
    t.append(2);

    t.append(0);
    t.append(0);
    t.append(3);
    t.append(1);
    t.append(0);
    t.append(3);
    t.append(5);
    t.append(0);
    t.append(3);

    t.append(0);
    t.append(0);
    t.append(3);
    t.append(5);
    t.append(0);
    t.append(3);
    t.append(4);
    t.append(0);
    t.append(3);

    t.append(4);
    t.append(0);
    t.append(4);
    t.append(5);
    t.append(0);
    t.append(4);
    t.append(7);
    t.append(0);
    t.append(4);

    t.append(4);
    t.append(0);
    t.append(4);
    t.append(7);
    t.append(0);
    t.append(4);
    t.append(6);
    t.append(0);
    t.append(4);

    t.append(2);
    t.append(0);
    t.append(5);
    t.append(3);
    t.append(0);
    t.append(5);
    t.append(1);
    t.append(0);
    t.append(5);

    t.append(2);
    t.append(0);
    t.append(5);
    t.append(1);
    t.append(0);
    t.append(5);
    t.append(0);
    t.append(0);
    t.append(5);

    return Mesh(v,t,vn, nom);
}

void MeshBuilder::saveMesh(const QString &nom, const Mesh &mesh) const
{
    QFile file(nom);
    cout<<"file create"<<endl;
    file.open((QIODevice::WriteOnly | QIODevice::Text));
    cout<<"file open"<<endl;
    QTextStream out(&file);
    cout<<"stream create"<<endl;
    out << "o "<<mesh.getNom()<<"\n";
    for(QList<Vector3D>::const_iterator itVect = mesh.getGeom().begin(); itVect != mesh.getGeom().end(); ++itVect) {
    out << "v " << itVect->x() << " " << itVect->y() << " " << itVect->z() << "\n";
    }
    out << "\n";

    cout<<"vertices ok"<<endl;

    for(QList<Vector3D>::const_iterator itNorm = mesh.getNorm().begin(); itNorm != mesh.getNorm().end(); ++itNorm) {
    out << "vn " << itNorm->x() << " " << itNorm->y() << " " << itNorm->z() << "\n";
    }
    out << "\n";

    out << "vt 0.0 0.0 \n\n";

    for(QList<int>::const_iterator it = mesh.getTopo().begin(); it != mesh.getTopo().end();) {
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
    cout<<"file close"<<endl;
}

Mesh MeshBuilder::terrain(const Terrain &t, int e, const QString &nom) const{

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
Mesh MeshBuilder::loadMesh(const QString &nom) const
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
