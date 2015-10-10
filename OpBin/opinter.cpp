#include "opinter.h"

OpInter::OpInter(Node *a, Node *b) :
    OpBin(a, b)
{

}

bool OpInter::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) && b->inOut(p));
}

bool OpInter::inOut(const glm::vec3& p, float& f) const
{
    float f2;
    bool in = (a->inOut(p,f) && b->inOut(p, f2));
    if(f > f2)
        f = f2;
    return in;
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

