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

bool &CSGDifference::intersect(const Ray &r, Qvector<double> &t) const
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
