#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include "mesh.h"
#include <QString>
#include "terrain.h"
#include "vector2d.h"
class MeshBuilder
{
private:

public:
    MeshBuilder();
    Mesh loadMesh(QString& nom);
    void saveMesh(QString& nom, Mesh &mesh);
    ~MeshBuilder();
    Mesh terrain(Terrain &t, Vector2D &a, Vector2D &b, int e, QString nom, double echelle);


};
#endif // MESHBUILDER_H
