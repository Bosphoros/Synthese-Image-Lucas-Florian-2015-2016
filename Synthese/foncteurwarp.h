#ifndef FONCTEURWARP_H
#define FONCTEURWARP_H
#include <QVector2D>
class FoncteurWarp
{
public:
    FoncteurWarp();
    virtual QVector2D operator()(QVector2D& p)=0;
};

#endif // FONCTEURWARP_H
