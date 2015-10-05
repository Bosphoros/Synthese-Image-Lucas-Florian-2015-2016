#include "tableauvoxel.h"

TableauVoxel::TableauVoxel(int lo, int la, int ha, double d):longueur(lo), largeur(la), hauteur(ha), definition(d)
{
    voxels.resize(longueur*largeur*hauteur);
}

Box TableauVoxel::getBox(int x, int y, int z)
{
    Vector3D a(x*definition,y*definition,z*definition);
    Vector3D b((x+1)*definition,(y+1)*definition,(z+1)*definition);

    return Box(a,b);
}

