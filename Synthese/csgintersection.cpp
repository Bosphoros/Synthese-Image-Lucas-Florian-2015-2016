#include "csgintersection.h"

CSGIntersection::CSGIntersection(CSGNode *n1, CSGNode *n2):CSGBinaire(n1,n2)
{

}

bool CSGIntersection::isIn(const Vector3D &p) const
{
    return (node1->isIn(p)&&node2->isIn(p));
}

bool &CSGIntersection::intersect(const Ray &r, Qvector<double> &t) const
{
    Qvector<double> ta;
    Qvector<double> tb;
    node1->intersect(r, ta);
    node2->intersect(r, tb);

    for(int cpt = 0; cpt < ta.size(); ta++)
    {
        //si le point d'intersection avec le premier noeud appartient également au second noeud
        //alors on concerve ce point
        if(node2->isIn(r.getPoint(ta.at(cpt))))
        {
            t.push_back(ta.at(cpt));
        }
    }

    for(int cpt = 0; cpt < tb.size(); tb++)
    {
        //si le point d'intersection avec le second noeud appartient également au premier noeud
        //alors on concerve ce point
        if(node1->isIn(r.getPoint(tb.at(cpt))))
        {
            t.push_back(tb.at(cpt));
        }
    }
}
