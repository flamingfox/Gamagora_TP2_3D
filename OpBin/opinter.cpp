#include "opinter.h"

OpInter::OpInter(Node *a, Node *b) :
    OpBin(a, b)
{

}

bool OpInter::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) && b->inOut(p));
}

float OpInter::potentiel(const glm::vec3& p) const
{
    return std::min(a->potentiel(p), b->potentiel(p));

}

float OpInter::distance(const glm::vec3 &p) const
{
    return std::min(a->distance(p), b->distance(p));
}

/*bool OpInter::intersect(const Rayon& r, float& t)
{
    float tTmp = 0;

    if(a.intersect(r, tTmp) && b.intersect(r, t)){

        if(tTmp < t)
            t = tTmp;

        retour = true;

    }
    return false;
}*/

glm::vec3 OpInter::getNormal(const vec3& p, float eps) const
{

    float e1 = a->potentiel(p);
    float e2 = b->potentiel(p);

    return normalize((a->getNormal(p,eps)*e1+b->getNormal(p,eps))/(e1+e2));
    //à revoir
}


QRgb OpInter::getColor(const vec3& p) const
{
    float ea = a->potentiel(p);
    float eb = b->potentiel(p);

    QRgb ca = a->getColor(p);
    QRgb cb = b->getColor(p);
    return (std::min(qRed(ca)*ea+qRed(cb)*eb,255.f),
            std::min(qGreen(ca)*ea+qGreen(cb)*eb,255.f),
            std::min(qBlue(ca)*ea+qBlue(cb)*eb,255.f));
}
