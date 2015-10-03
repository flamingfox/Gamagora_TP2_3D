#include "opinter.h"

OpInter::OpInter(CSG_Primitive* a, CSG_Primitive* b) :
    OpBin(a, b)
{

}

bool OpInter::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) && b->inOut(p));
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

