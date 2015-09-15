#ifndef OCTAVE_H
#define OCTAVE_H
#include "foncteurwarp.h"
#include "noise.h"

class Octave
{
private:
    float freq;
    float ampli;
    float minSeuil;
    float ampliS;
    float freqS;

    FoncteurWarp warpPoint;
    FoncteurWarp warpSeuil;

    Noise noisePoint;
    Noise noiseSeuil;

public:
    Octave();
    Octave(const Octave& o);
    Octave(float f, float a, float ms, float as, float fs, FoncteurWarp wPoint, FoncteurWarp wSeuil, Noise nPoint, Noise nSeuil);
    float getHauteur(const Vector2D &p);
};

#endif // OCTAVE_H
