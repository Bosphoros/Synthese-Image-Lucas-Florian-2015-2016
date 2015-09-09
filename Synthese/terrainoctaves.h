#ifndef TERRAINOCTAVES_H
#define TERRAINOCTAVES_H
#include "terrain.h"
#include "octave.h"
#include <QVector>

class TerrainOctaves : public Terrain
{
private:
    quint16 echantillons;
    std::vector<quint16> mat;
    QVector<Octave> octaves;

public:
    TerrainOctaves(QVector<Octave>& o, QVector2D& aa, QVector2D& bb, quint16 e);
    virtual quint16 getHauteur(const QVector2D &p);
    virtual quint16 getHauteurMin();
    virtual quint16 getHauteurMax();
    virtual double getPenteMax();

};

#endif // TERRAINOCTAVES_H
