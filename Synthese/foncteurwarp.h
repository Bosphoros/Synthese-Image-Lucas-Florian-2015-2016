#ifndef FONCTEURWARP_H
#define FONCTEURWARP_H
#include "vector2d.h"
class FoncteurWarp
{
public:
    FoncteurWarp();
    virtual Vector2D operator()(Vector2D& p);
};

#endif // FONCTEURWARP_H
