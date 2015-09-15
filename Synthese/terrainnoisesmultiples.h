#ifndef TERRAINNOISESMULTIPLES_H
#define TERRAINNOISESMULTIPLES_H
#include "terrain.h"
#include <vector>

class TerrainNoisesMultiples : public Terrain
{
private:
    double altitudeMinimum;
    std::vector<double> amplitudes;
    std::vector<double> frequences;
public:
    TerrainNoisesMultiples(double am,const std::vector<double>& lFreqs,const std::vector<double>& lAmpl, const Vector2D &aa, const Vector2D &bb);
    virtual double getHauteur(const Vector2D& p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

inline double TerrainNoisesMultiples::getHauteurMin() const {
    return altitudeMinimum;
}

#endif // TERRAINNOISESMULTIPLES_H
