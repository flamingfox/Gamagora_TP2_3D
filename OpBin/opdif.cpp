#include "opdif.h"


OpDif::OpDif(CSG_Primitive* _a, CSG_Primitive* _b):
    OpBin(_a, _b)
{
}

bool OpDif::inOut(const glm::vec3 &p) const
{
    return (a->inOut(p) && !b->inOut(p));
}
