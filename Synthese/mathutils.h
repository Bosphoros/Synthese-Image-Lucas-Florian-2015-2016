#ifndef MATHUTILS_H
#define MATHUTILS_H

class MathUtils
{
public:
    MathUtils();
    static double fonctionQuadratique(double min, double max, double x);
    static double fonctionQuadratiqueInv(double min, double max, double x);
    static double interpolate(double before_p0, double p0, double p1, double after_p1, double t);
    static double ridge(double n, double s);
    static double mod(double a, double b);
};

#endif // MATHUTILS_H
