#include "csgunion.h"

CSGUnion::CSGUnion(CSGNode *n1, CSGNode *n2):CSGBinaire(n1,n2)
{

}

bool CSGUnion::isIn(const Vector3D &p) const
{
    return (node1->isIn(p)||node2->isIn(p));
}

bool &CSGUnion::intersect(const Ray &r, Qvector<double> &intersects) const
{
    Qvector<double> ta;
    Qvector<double> tb;
    node1->intersect(r, ta);
    node2->intersect(r, tb);

    for(int cpt = 0; cpt < ta.size(); ta++)
    {
        //si le point d'intersection avec le premier noeud n'appartient pas au second noeud
        //alors on concerve ce point
        if(node2->isOut(r.getPoint(ta.at(cpt))))
        {
            intersects.push_back(ta.at(cpt));
        }
    }

    for(int cpt = 0; cpt < tb.size(); tb++)
    {
        //si le point d'intersection avec le second noeud n'appartient pas au premier noeud
        //alors on concerve ce point
        if(node1->isOut(r.getPoint(tb.at(cpt))))
        {
            intersects.push_back(tb.at(cpt));
        }
    }
}

