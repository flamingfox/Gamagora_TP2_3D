#include "opunion.h"

OpUnion::OpUnion(Node* a, Node* b) :
    OpBin(a, b)
{
}


bool OpUnion::inOut(const glm::vec3& p) const
{
    return (a->inOut(p) || b->inOut(p));
}

bool OpUnion::inOut(const glm::vec3& p, float& f) const
{
    float f2;
    a->inOut(p,f);
    b->inOut(p, f2);
    f *= f;
    f += f2*f2;
    if(f > 1.f)
        f = 1.f;
    return f == 1.f;
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

