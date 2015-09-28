#include "octave.h"
#include "mathutils.h"

Octave::Octave()
{

}

Octave::Octave(const Octave &o):freq(o.freq), ampli(o.ampli), minSeuil(o.minSeuil), ampliS(o.ampliS), freqS(o.freqS), warpPoint(o.warpPoint), warpSeuil(o.warpSeuil), noisePoint(o.noisePoint), noiseSeuil(o.noiseSeuil)
{

}

Octave::Octave(double f, double a, double ms, double as, double fs, const FoncteurWarp &wPoint, const FoncteurWarp &wSeuil, const Noise &nPoint, const Noise &nSeuil):freq(f), ampli(a), minSeuil(ms), ampliS(as), freqS(fs), warpPoint(wPoint), warpSeuil(wSeuil), noisePoint(nPoint), noiseSeuil(nSeuil)
{
}

double Octave::getHauteur(const Vector2D &p)
{
    Vector2D pSurFreq = p/freq;
    Vector2D pFreqS = p/freqS;
    Vector2D wPoint = warpPoint(pSurFreq);
    Vector2D wSeuil = warpSeuil(pFreqS);
    double r = MathUtils::ridge(ampli*noisePoint.pointToValue(wPoint),
                minSeuil+ampliS*noiseSeuil.pointToValue(wSeuil));
    return r;
}