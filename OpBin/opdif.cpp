#include "opdif.h"


OpDif::OpDif(Node *_a, Node *_b):
    OpBin(_a, _b)
{
}

bool OpDif::inOut(const glm::vec3 &p) const
{
    return (a->inOut(p) && !b->inOut(p));
}

bool OpDif::inOut(const glm::vec3& p, float& f) const
{
    float f2;
    a->inOut(p,f);
    b->inOut(p, f2);
    if(f2 >= 1.f)   //on enlève seulement la partie qui est effectivement dedans
        f -= f2;
    if(f < 0.f)
        f = 0.f;
    return f == 1.f;
}
