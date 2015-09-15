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
    virtual double getHauteurMin(Vector2D a,Vector2D b);
    virtual double getHauteurMax(Vector2D a,Vector2D b);
    virtual double getPenteMax(Vector2D a, Vector2D b);

};

#endif // TERRAINOCTAVES_H
