#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include "mesh.h"
#include <QString>
class MeshBuilder
{
private:

public:
    MeshBuilder();
    Mesh loadMesh(QString& nom);
    void saveMesh(QString& nom, Mesh &mesh);
    ~MeshBuilder();


};
#endif // MESHBUILDER_H
