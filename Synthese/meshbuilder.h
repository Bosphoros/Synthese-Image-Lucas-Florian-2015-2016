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
    Mesh loadMesh(const QString& nom) const;
    void saveMesh(const QString& nom, const Mesh &mesh) const;
    ~MeshBuilder();
    Mesh terrain(const Terrain &t, int e, const QString &nom) const;


};
#endif // MESHBUILDER_H
