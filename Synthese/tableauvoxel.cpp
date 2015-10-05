#include "tableauvoxel.h"

TableauVoxel::TableauVoxel(int lo, int la, int ha, double d, Vector3D aa):a(aa), longueur(lo), largeur(la), hauteur(ha), definition(d)
{
    voxels.resize(longueur*largeur*hauteur);
}

Box TableauVoxel::getBox(int x, int y, int z) const
{
    Vector3D aa(x*definition,y*definition,z*definition);
    aa+=a;
    Vector3D bb((x+1)*definition,(y+1)*definition,(z+1)*definition);
    bb+=a;

    return Box(aa,bb);
}

