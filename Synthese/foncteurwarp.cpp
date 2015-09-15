#include "foncteurwarp.h"
#include "noise.h"
#include "vector2d.h"
FoncteurWarp::FoncteurWarp()
{

}

Vector2D FoncteurWarp::operator()(Vector2D &p)
{
    Noise n(156874);
    Vector2D v=n.pointToPoint(p);
    return p+v;
}
