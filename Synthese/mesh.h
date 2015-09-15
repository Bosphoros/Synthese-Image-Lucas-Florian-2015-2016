#ifndef MESH_H
#define MESH_H
#include "vector3d.h"
#include <QMatrix3x3>
#include<QList>

class Mesh
{
private:
    QString nom;
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> norm;
public:
    Mesh();
    Mesh(const Mesh& m);
    Mesh(QList<Vector3D>& v, QList<int>& t, QList<Vector3D>& n,QString& no);
    void translate(Vector3D& t);
    void rotate(const QMatrix3x3& mat);
    void homotecie(Vector3D &c, double h);
    void merge(const Mesh& mesh);
    int containsGeom(const Vector3D& g);
    int containsNorm(const Vector3D &n);
    QList<Vector3D>& getGeom();
    QList<Vector3D>& getNorm();
    QList<int>& getTopo();
    QString& getNom();
    ~Mesh();
};

#endif // MESH_H
