#include "foncteurwarp.h"
#include "noise.h"
#include <QVector2D>
FoncteurWarp::FoncteurWarp()
{

}

QVector2D FoncteurWarp::operator()(QVector2D &p)
{
    Noise n(156874);
    QVector2D v=n.pointToPoint(p);
    return p+v;
}
