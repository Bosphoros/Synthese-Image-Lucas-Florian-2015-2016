#ifndef NOISE_H
#define NOISE_H
#include <QVector2D>
class Noise
{
private:
    int seed;
public:
    Noise(int seed=0);
    float pointToValue(QVector2D& p);
    QVector2D pointToPoint(QVector2D& p);
};

#endif // NOISE_H
