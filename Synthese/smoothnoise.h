#ifndef SMOOTHNOISE_H
#define SMOOTHNOISE_H
#include <QVector2D>

double smooth_noise(QVector2D p, int seed);
double smooth_noiseABS(QVector2D p, int seed);


#endif // SMOOTHNOISE_H
