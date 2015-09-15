#include "smoothnoise.h"
#include <cmath>
#include "mathutils.h"
double noise(int t,int seed)
{
       double fract=(1+sin(t))*abs(43758.5453123+seed);
       int entier=(int) fract;
       return fract-entier;
}
double noise(int x, int y,int seed)
{
    int tmp = noise(x,seed) * abs(850000+seed);
    return noise(tmp + y,seed);
}


double cubic_interpolate(double before_p0, double p0,
             double p1, double after_p1, double t)
{
    //Calcul des coefficients de notre polynôme
    double a3 = -0.5*before_p0 + 1.5*p0 - 1.5*p1 + 0.5*after_p1;
    double a2 = before_p0 - 2.5*p0 + 2*p1 - 0.5*after_p1;
    double a1 = -0.5*before_p0 + 0.5*p1;
    double a0 = p0;

    //Calcul de la valeur de ce polynôme en t
    return (a3 * t*t*t) + (a2 * t*t) + (a1 * t) + a0;

}


double smooth_noise_firstdim(int integer_x,
                int integer_y, double fractional_x,int seed)
{
    double v0 = noise(integer_x - 1, integer_y,seed);
    double v1 = noise(integer_x,     integer_y,seed);
    double v2 = noise(integer_x + 1, integer_y,seed);
    double v3 = noise(integer_x + 2, integer_y,seed);

    return cubic_interpolate(v0, v1, v2, v3, fractional_x);
}

double bilinearInterpolate(double xy, double x1y,double xy1, double x1y1, Vector2D p){

    return (1-p.x())*(1-p.y())*xy + p.x()*(1-p.y())*x1y +
           (1-p.x())*p.y()*xy1 +  p.x()*p.y()*x1y1;
}

double smooth_noiseBilinear(Vector2D p,int seed){
    float x;
    float y;
    float fractional_x;
    float fractional_y;
    int integer_x;
    int integer_y;
    if(p.x()>=0){
        x=p.x();
        integer_x = (int)x;
        fractional_x = x - integer_x;
    }
    else{
        integer_x=((int)p.x())-1;
        fractional_x=p.x()-integer_x;

    }

    if(p.y()>=0){
        y=p.y();
        integer_y = (int)y;
        fractional_y = y - integer_y;
    }
    else{
        integer_y=((int)p.y())-1;
        fractional_y=p.y()-integer_y;

    }
        Vector2D pf(fractional_x,fractional_y);
        double xy = noise(integer_x,integer_y,seed);
        double x1y = noise(integer_x+1,integer_y,seed);
        double xy1 = noise(integer_x,integer_y+1,seed);
        double x1y1 = noise(integer_x+1,integer_y+1,seed);

        return bilinearInterpolate(xy,x1y,xy1,x1y1,pf);
}


double smooth_noise(Vector2D p,int seed){
    double x=p.x();
    double y=p.y();
    int integer_x = (int)x;
        double fractional_x = x - integer_x;
        int integer_y = (int)y;
        double fractional_y = y - integer_y;

        double t0 = smooth_noise_firstdim(integer_x,
                        integer_y - 1, fractional_x,seed);
        double t1 = smooth_noise_firstdim(integer_x,
                        integer_y,     fractional_x,seed);
        double t2 = smooth_noise_firstdim(integer_x,
                        integer_y + 1, fractional_x,seed);
        double t3 = smooth_noise_firstdim(integer_x,
                        integer_y + 2, fractional_x,seed);

        double resu= cubic_interpolate(t0, t1, t2, t3, fractional_y);
        return MathUtils::fonctionQuadratique(-0.2,1.2,resu);
}
