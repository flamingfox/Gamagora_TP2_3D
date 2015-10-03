#include "opunion.h"

OpUnion::OpUnion(CSG_Primitive* a, CSG_Primitive* b) :
    OpBin(a, b)
{
}


bool OpUnion::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) || b->inOut(p));
}

/*bool OpUnion::intersect(const Rayon& r, float& t)
{
    float tTmp =  ;

    if(a.intersect(r, tTmp) || b.intersect(r, t)){

        if(tTmp < t)
            t = tTmp;

        retour = true;

    }
}*/

