#include "csgdifference.h"

CSGDifference::CSGDifference(CSGNode *n1, CSGNode *n2):CSGBinaire(n1,n2)
{

}

bool CSGDifference::isIn(const Vector3D &p) const
{
    if(node1->isIn(p))
    {
        if(node2->isOut(p))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool CSGDifference::intersect(const Ray &r, QVector<double>& intersects, QVector<Vector3D> &normals) const

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
        //si le point d'intersection avec le second noeud appartient également au premier noeud
        //alors on conserve ce point
        if(node1->isIn(r.getPoint(tb.at(cpt))))
        {
            intersects.push_back(tb.at(cpt));
            normals.push_back(-normalB.at(cpt));
        }
    }
    return intersects.size()>0;
}
