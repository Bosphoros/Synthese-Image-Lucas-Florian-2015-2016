#include "octave.h"
#include "mathutils.h"

Octave::Octave()
{

}

Octave::Octave(const Octave &o):freq(o.freq), ampli(o.ampli), minSeuil(o.minSeuil), ampliS(o.ampliS), freqS(o.freqS), warpPoint(o.warpPoint), warpSeuil(o.warpSeuil), noisePoint(o.noisePoint), noiseSeuil(o.noiseSeuil)
{

}

Octave::Octave(float f, float a, float ms, float as, float fs, FoncteurWarp wPoint, FoncteurWarp wSeuil, Noise nPoint, Noise nSeuil):freq(f), ampli(a), minSeuil(ms), ampliS(as), freqS(fs), warpPoint(wPoint), warpSeuil(wSeuil), noisePoint(nPoint), noiseSeuil(nSeuil)
{
}

quint16 Octave::getHauteur(const QVector2D &p)
{
    QVector2D pSurFreq = p/freq;
    QVector2D pFreqS = p/freqS;
    QVector2D wPoint = warpPoint(pSurFreq);
    QVector2D wSeuil = warpSeuil(pFreqS);
    quint16 r = MathUtils::ridge(ampli*noisePoint.pointToValue(wPoint),
                minSeuil+ampliS*noiseSeuil.pointToValue(wSeuil));
    return r;
}
