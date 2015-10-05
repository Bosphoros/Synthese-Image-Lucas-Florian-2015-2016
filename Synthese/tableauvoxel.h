#ifndef TABLEAUVOXEL_H
#define TABLEAUVOXEL_H

#include <QVector>
#include "box.h"

class TableauVoxel
{
private:
    QVector<int> voxels;
    int longueur;
    int largeur;
    int hauteur;
    QVector3D a;
    double definition;

public:
    TableauVoxel(int lo, int la, int ha, double d, Vector3D aa);
    int operator()(int x, int y, int z) const;
    int& operator ()(int x, int y, int z) ;
    int getLongueur() const;
    int getLargeur() const;
    int getHauteur() const;
    Box getBox(int x, int y, int z) const;
};

inline int TableauVoxel::operator()(int x, int y, int z) const{
    return voxels.at(z*longueur*largeur+y*largeur+x);
}

inline int& TableauVoxel::operator ()(int x, int y, int z) {
    return voxels[z*longueur*largeur+y*largeur+x];
}

inline int TableauVoxel::getLongueur() const{
    return longueur;
}

inline int TableauVoxel::getLargeur() const{
    return largeur;
}

inline int TableauVoxel::getHauteur() const{
    return hauteur;
}

#endif // TABLEAUVOXEL_H
