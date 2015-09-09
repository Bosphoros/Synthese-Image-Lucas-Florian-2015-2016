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
    virtual float getHauteurMin(QVector2D a,QVector2D b);
    virtual float getHauteurMax(QVector2D a,QVector2D b);
    virtual double getPenteMax(QVector2D a, QVector2D b);

};

#endif // TERRAINOCTAVES_H
