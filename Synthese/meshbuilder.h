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
    Mesh terrain(Terrain &t, int e, QString nom);


};
#endif // MESHBUILDER_H
