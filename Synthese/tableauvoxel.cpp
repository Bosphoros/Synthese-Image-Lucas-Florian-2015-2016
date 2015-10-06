#include "tableauvoxel.h"
#include <iostream>

TableauVoxel::TableauVoxel(int lo, int la, int ha, double d, Vector3D aa):a(aa), longueur(lo), largeur(la), hauteur(ha), definition(d)
{
    voxels.resize(longueur*largeur*hauteur);
}

TableauVoxel::TableauVoxel(int lo, int la, int ha, double d, const Vector3D &aa, const CSGNode &node):a(aa), longueur(lo), largeur(la), hauteur(ha), definition(d)
{
    voxels.resize(longueur*largeur*hauteur);
    for(int i=0;i<longueur;++i){
        for(int j=0;j<largeur;++j){
            for(int k=0;k<hauteur;++k){
                Box b=getBox(i,j,k);
                Vector3D point=(b.getA()+b.getB())/2;
                //std::cout<<point<<std::endl;
                if(node.isIn(point)){
                    operator ()(i,j,k)=1;
                }

            }
        }
    }
}

Box TableauVoxel::getBox(int x, int y, int z) const
{
    Vector3D aa(x*definition,y*definition,z*definition);
    aa+=a;
    Vector3D bb((x+1)*definition,(y+1)*definition,(z+1)*definition);
    bb+=a;
    return Box(aa,bb);
}

