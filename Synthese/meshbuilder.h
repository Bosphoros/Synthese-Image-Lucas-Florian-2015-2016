#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include "mesh.h"
#include <QString>
#include "terrain.h"
#include "vector2d.h"
#include "tableauvoxel.h"
#include "box.h"

/**
 * @brief The MeshBuilder class, contains methods to create and load meshes
 */
class MeshBuilder
{
public:
    /**
     * Empty MeshBuilder constructor
     */
    MeshBuilder();

    /**
     * Creates the Mesh of a Box
     * @param[in] box the Box we want the Mesh of
     * @param[in] nom the name of the Mesh
     * @return The Mesh of the Box
     */
    Mesh box(const Box& box, const QString &nom) const;

    /**
     * Loads a mesh for a file
     * @param[in] nom The file location to load from
     * @return The constructed mesh
     */
    Mesh loadMesh(const QString& nom) const;

    /**
     * Saves the mesh to a file
     * @param[in] nom The file location to save in
     * @param[in] mesh The mesh to save
     */
    void saveMesh(const QString& nom, const Mesh &mesh) const;

    /**
     * Destructor of MeshBuilder, empty.
     */
    ~MeshBuilder();

    /**
     * Creates a Mesh based on a Terrain
     * @param[in] t The Terrain to base the Mesh on
     * @param[in] e The number of samples
     * @param[in] nom The name of the mesh to create
     * @return A Mesh based on samples of t
     */
    Mesh terrain(const Terrain &t, int e, const QString &nom) const;

    /**
     * Creates the Mesh of a Voxel Matrix
     * @param[in] t the Voxel Matric we want the Mesh of
     * @param[in] nom the name of the Mesh
     * @return The Mesh of the Voxel Matrix
     */
    Mesh voxel(const TableauVoxel &t, const QString &nom) const;

};
#endif // MESHBUILDER_H
