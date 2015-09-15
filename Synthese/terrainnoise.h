#ifndef TERRAINNOISE_H
#define TERRAINNOISE_H
#include "terrain.h"
class TerrainNoise: public Terrain
{
private:
    double altitudeMinimun;
    double amplitude;
    double invfrequence;
public:
    TerrainNoise(double am, double ampl, double freq, const Vector2D &aa, const Vector2D &bb);
    virtual double getHauteur(const Vector2D& p) const;
    virtual double getHauteurMin() const;
    virtual double getHauteurMax() const;
    virtual double getPenteMax() const;
};

    inline double TerrainNoise::getHauteurMin() const{
        return altitudeMinimun;
    }

    inline double TerrainNoise::getHauteurMax() const{
        return altitudeMinimun+amplitude;
    }

#endif // TERRAINNOISE_H
