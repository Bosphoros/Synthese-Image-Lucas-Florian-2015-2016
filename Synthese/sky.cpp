#include "sky.h"
#include "mathutils.h"

Vector3D Sky::getDirSol() const
{
    return dirSol;
}

void Sky::setDirSol(const Vector3D &value)
{
    dirSol = value;
}

float Sky::getNuage() const
{
    return nuage;
}

void Sky::setNuage(float value)
{
    nuage = value;
}

Sky::Sky()
{

}

QColor clamp(QColor light)
{
    int r = (int)MathUtils.clamp(0,255, light.red());
    int g = (int)MathUtils.clamp(0,255, light.green());
    int b = (int)MathUtils.clamp(0,255, light.blue());
    return QColor(r,g,b,0);
}

QColor Sky::getLight(Vector3D direction)
{
    direction.normalize();
    QColor colConstante(255,255,255,0);
    QColor colSoleil(255,255,255,0);
    QColor light = (colConstante * nuage) + colSoleil * (1-nuage) * (dirsol*direction);

    return clamp(light);
}
