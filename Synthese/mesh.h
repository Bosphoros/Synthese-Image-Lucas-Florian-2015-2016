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
    Mesh(const QList<Vector3D>& v, const QList<int>& t, const QList<Vector3D>& n,const QString& no);
    void translate(const Vector3D& t);
    void rotate(const QMatrix3x3& mat);
    void homotecie(const Vector3D &c, double h);
    void merge(const Mesh& mesh);
    int containsGeom(const Vector3D& g);
    int containsNorm(const Vector3D& n);
    QList<Vector3D> getGeom() const;
    QList<Vector3D> getNorm() const;
    QList<int> getTopo() const;
    QString getNom() const;
    ~Mesh();
};

#endif // MESH_H
