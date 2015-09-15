#ifndef TERRAINOCTAVES_H
#define TERRAINOCTAVES_H
#include "terrain.h"
#include "octave.h"
#include <QVector>

class TerrainOctaves : public Terrain
{
private:
    QVector<Octave> octaves;

public:
    TerrainOctaves(QVector<Octave>& o, const Vector2D &aa, const Vector2D &bb);
    virtual double getHauteur(const Vector2D &p);
    virtual double getHauteurMin(const Vector2D& aa, const Vector2D& bb);
    virtual double getHauteurMax(const Vector2D& aa, const Vector2D& bb);
    virtual double getPenteMax(const Vector2D& aa, const Vector2D& bb);

};

#endif // TERRAINOCTAVES_H
