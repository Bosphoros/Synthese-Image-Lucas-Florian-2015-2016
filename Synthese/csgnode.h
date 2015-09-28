#ifndef CSGNODE_H
#define CSGNODE_H
#include "vector3d.h"
#include "ray.h"
#include "QVector"

class CSGNode
{
public:

    virtual bool isIn(const Vector3D& p) const =0;
    bool isOut(const Vector3D& p) const ;
    virtual QVector<Vector3D>& intersect(const Ray& r) const =0;

};

inline bool isOut(const Vector3D& p)const{
    return !isIn(p);
}

#endif // CSGNODE_H
