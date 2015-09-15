#ifndef OCTAVE_H
#define OCTAVE_H
#include "foncteurwarp.h"
#include "noise.h"

class Octave
{
private:
    double freq;
    double ampli;
    double minSeuil;
    double ampliS;
    double freqS;

    FoncteurWarp warpPoint;
    FoncteurWarp warpSeuil;

    Noise noisePoint;
    Noise noiseSeuil;

public:
    Octave();
    Octave(const Octave& o);
    Octave(double f, double a, double ms, double as, double fs, const FoncteurWarp& wPoint, const FoncteurWarp& wSeuil, const Noise& nPoint, const Noise& nSeuil);
    double getHauteur(const Vector2D &p);
};

#endif // OCTAVE_H
