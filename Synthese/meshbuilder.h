#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include "mesh.h"
#include <QString>
#include "terrain.h"
#include "QVector2D"
class MeshBuilder
{
private:

public:
    MeshBuilder();
    Mesh loadMesh(QString& nom);
    void saveMesh(QString& nom, Mesh &mesh);
    ~MeshBuilder();
    Mesh terrain(Terrain &t, QVector2D &a, QVector2D &b, int e, QString nom, double echelle);


};
#endif // MESHBUILDER_H
