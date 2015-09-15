#include "smoothnoise.h"
#include <cmath>
#include "mathutils.h"

int fastfloor( const double x ) { return x > 0 ? (int) x : (int) x - 1; }
double dot( const int* g, const double x, const double y ) { return g[0]*x + g[1]*y; }

// 2D raw Simplex noise
double raw_noise_2d( const double x, const double y )
{
    // Noise contributions from the three corners
    double n0, n1, n2;

    // Skew the input space to determine which simplex cell we're in
    double F2 = 0.5 * (sqrt(3.0) - 1.0);
    // Hairy factor for 2D
    double s = (x + y) * F2;
    int i = fastfloor( x + s );
    int j = fastfloor( y + s );

    double G2 = (3.0 - sqrt(3.0)) / 6.0;
    double t = (i + j) * G2;
    // Unskew the cell origin back to (x,y) space
    double X0 = i-t;
    double Y0 = j-t;
    // The x,y distances from the cell origin
    double x0 = x-X0;
    double y0 = y-Y0;

    // For the 2D case, the simplex shape is an equilateral triangle.
    // Determine which simplex we are in.
    int i1, j1; // Offsets for second (middle) corner of simplex in (i,j) coords
    if(x0>y0) {i1=1; j1=0;} // lower triangle, XY order: (0,0)->(1,0)->(1,1)
    else {i1=0; j1=1;} // upper triangle, YX order: (0,0)->(0,1)->(1,1)

    // A step of (1,0) in (i,j) means a step of (1-c,-c) in (x,y), and
    // a step of (0,1) in (i,j) means a step of (-c,1-c) in (x,y), where
    // c = (3-sqrt(3))/6
    double x1 = x0 - i1 + G2; // Offsets for middle corner in (x,y) unskewed coords
    double y1 = y0 - j1 + G2;
    double x2 = x0 - 1.0 + 2.0 * G2; // Offsets for last corner in (x,y) unskewed coords
    double y2 = y0 - 1.0 + 2.0 * G2;

    // Work out the hashed gradient indices of the three simplex corners
    int ii = i & 255;
    int jj = j & 255;
    int gi0 = perm[ii+perm[jj]] % 12;
    int gi1 = perm[ii+i1+perm[jj+j1]] % 12;
    int gi2 = perm[ii+1+perm[jj+1]] % 12;

    // Calculate the contribution from the three corners
    double t0 = 0.5 - x0*x0-y0*y0;
    if(t0<0) n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 * dot(grad3[gi0], x0, y0); // (x,y) of grad3 used for 2D gradient
    }

    double t1 = 0.5 - x1*x1-y1*y1;
    if(t1<0) n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * dot(grad3[gi1], x1, y1);
    }

    double t2 = 0.5 - x2*x2-y2*y2;
    if(t2<0) n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * dot(grad3[gi2], x2, y2);
    }

    // Add contributions from each corner to get the final noise value.
    // The result is scaled to return values in the interval [-1,1].
    return (1+(70.0 * (n0 + n1 + n2)))/2;
}

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
    double x;
    double y;
    double fractional_x;
    double fractional_y;
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
