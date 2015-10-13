#include "opunion.h"

OpUnion::OpUnion(Node* a, Node* b) :
    OpBin(a, b)
{
}


bool OpUnion::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) || b->inOut(p));
}

float OpUnion::potentiel(const glm::vec3& p) const
{
    return std::max(a->potentiel(p), b->potentiel(p));
}

/*bool OpUnion::intersect(const Rayon& r, float& t)
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
}*/

