#include "terrain.h"
#include <iostream>
Terrain::Terrain(const Vector2D &aa, const Vector2D &bb):penteMax(-1),a(aa),b(bb)
{

}

Vector3D Terrain::norm(const Vector2D &p)
{
   /* Vector2D px(p.x()+epsilon,p.y());
    Vector2D py(p.x(),p.y()+epsilon);

    double hp=getHauteur(p);
    double hpx=getHauteur(px);
    double hpy=getHauteur(py);

    Vector3D vp(p.x(),p.y(),(double)hp);

    Vector3D vpx(px.x(),px.y(),(double)hpx);

    Vector3D vpy(py.x(),py.y(),(double)hpy);

    Vector3D u=vpx-vp;
    Vector3D v=vpy-vp;

    Vector3D n(-u.z()/u.x(),1.0f,-v.z()/v.y());
    n.normalize();

    return n;*/

    //std::cout<<p.x()<<" "<<p.x()+epsilon<<std::endl;

    Vector2D px(p.x()+epsilon,p.y());
    Vector2D pxminus(p.x()-epsilon, p.y());
    Vector2D py(p.x(),p.y()+epsilon);
    Vector2D pyminus(p.x(),p.y()-epsilon);

    double hpx=getHauteur(px);
    double hpxminus = getHauteur(pxminus);
    double hpy=getHauteur(py);
    double hpyminus = getHauteur(pyminus);
    //std::cout<<hpx<<" "<<hpxminus << "/ " << hpy << " " << hpyminus<<std::endl;
    //std::cout<<(hpx-hpxminus)/(2*epsilon)<<std::endl;
    Vector3D resu(-(hpx-hpxminus),2*epsilon,-(hpy-hpyminus));
    resu.normalize();
    return resu;


}


bool Terrain::isIn(const Vector3D &p)
{
    Vector2D p2(p.x(),p.z());
    return p.y()<=getHauteur(p2);
}

bool Terrain::isOut(const Vector3D &p)
{
    Vector2D p2(p.x(),p.z());
    return p.y()>getHauteur(p2);
}

double Terrain::getHauteurNormale(const Vector2D &p, Vector3D &n)
{
    n=norm(p);
    double resu=getHauteur(p);
    return resu;
}


bool Terrain::intersectRayMarching(const Ray& ray, const Vector3D &aBox, const Vector3D &bBox, Vector3D& resu, bool& isBox)
{
    isBox=false;
    resu=ray.origine;

    Vector3D in;
    Vector3D out;

    int pointsBox = ray.intersectsBox(aBox, bBox, in, out);

    if(pointsBox == 0) {
        //std::cout<<"return false"<<std::endl;
        return false;
    }
    double distInOut = in.distanceToPoint(out);
    Vector3D dir=ray.direction;
    Ray r(in,dir);
    //std::cout << pas << " " << dir.x() << "," << dir.y() << "," << dir.z() << " / " << origine.x() << "," << origine.y() << "," << origine.z() << std::endl;
    for(double tt = 0; tt <= distInOut+pas; tt+= pas)
    {
        //std::cout<<r.getPoint(tt).y()<<std::endl;
        if(isIn(r.getPoint(tt))){

            resu=r.getPoint(tt-pas/2);
            if(tt==0){
                isBox=true;
            }
            return true;
         }

    }

    return false;
}

bool Terrain::intersectAdvanced(const Ray &r, const Vector2D &aa, const Vector2D &bb, Vector3D &resu) const
{

    /*resu=origine;
    double min =t.getHauteurMin(a,b);
    double max =t.getHauteurMax(a,b);

    Vector3D aBox(a.x(), min, a.y());
    Vector3D bBox(b.x(), max, b.y());
    Vector3D in;
    Vector3D out;

    int pointsBox = intersectsBox(aBox, bBox, in, out);

    if(pointsBox == 0) {
        //std::cout<<"return false"<<std::endl;
        return false;
    }
    double distInOut = in.distanceToPoint(out);
    Vector3D dir=direction;
    Ray r(in,dir);
    double penteMax=t.getPenteMax(a,b);
    for(double tt = 0; tt <= distInOut+pas; tt+= pas)
    {
        //std::cout<<r.getPoint(tt).y()<<std::endl;
        Vector3D point=r.getPoint(tt);
        if(t.isIn(point)){
            resu=r.getPoint(tt-pas/2);
            return true;
        }

        Vector2D p(point.x(),point.z());
        double hauteur=t.getHauteur(p);
        double dif=point.y()-hauteur;
        if (direction.y()>penteMax){
            return false;
        }
        //std::cout << dif/(penteMax-direction.y()) << std::endl;
        tt+=dif/(penteMax-direction.y());

    }
*/
    return false;
}

double Terrain::epsilon=0.0000001;
double Terrain::pas=0.1;
