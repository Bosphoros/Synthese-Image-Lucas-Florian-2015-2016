#ifndef TERRAINOCTAVES_H
#define TERRAINOCTAVES_H
#include "terrain.h"
#include "octave.h"
#include <QVector>

class TerrainOctaves : public Terrain
{
private:
    std::vector<quint16> mat;
    QVector<Octave> octaves;

public:
    TerrainOctaves(QVector<Octave>& o);
    virtual float getHauteur(const QVector2D &p);
    virtual float getHauteurMin();
    virtual float getHauteurMax();
    virtual double getPenteMax();

};

#endif // TERRAINOCTAVES_H
