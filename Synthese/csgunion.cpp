#include "csgunion.h"

CSGUnion::CSGUnion(CSGNode *n1, CSGNode *n2):CSGBinaire(n1,n2)
{

}

bool CSGUnion::isIn(const Vector3D &p) const
{
    return (node1->isIn(p)||node2->isIn(p));
}

bool CSGUnion::intersect(const Ray &r, QVector<double> &intersects, QVector<Vector3D> &normals) const
{
    QVector<double> ta;
    QVector<double> tb;
    QVector<Vector3D> normalA;
    QVector<Vector3D> normalB;
    node1->intersect(r, ta, normalA);
    node2->intersect(r, tb, normalB);

    for(int cpt = 0; cpt < ta.size(); ++cpt)
    {
        //si le point d'intersection avec le premier noeud n'appartient pas au second noeud
        //alors on conserve ce point
        if(node2->isOut(r.getPoint(ta.at(cpt))))
        {
            intersects.push_back(ta.at(cpt));
            normals.push_back(normalA.at(cpt));
        }
    }

    for(int cpt = 0; cpt < tb.size(); ++cpt)
    {
        //si le point d'intersection avec le second noeud n'appartient pas au premier noeud
        //alors on conserve ce point
        if(node1->isOut(r.getPoint(tb.at(cpt))))
        {
            intersects.push_back(tb.at(cpt));
            normals.push_back(normalB.at(cpt));
        }
    }

    return intersects.size()>0;
}

