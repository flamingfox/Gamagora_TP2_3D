#include "opunion.h"

OpUnion::OpUnion(CSG_Primitive* a, CSG_Primitive* b) :
    OpBin(a, b)
{
}


bool OpUnion::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) || b->inOut(p));
}

bool OpUnion::intersect(const Rayon& r, float& t)
{
    bool ba = a->intersect(r, t);

    float tTmp;
    if(b->intersect(r, tTmp))
    {
        if(ba == false || tTmp < t)
            t = tTmp;
        return true;
    }
    else
        return ba;
}

