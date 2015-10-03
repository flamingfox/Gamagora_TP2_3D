#ifndef OPUNION_H
#define OPUNION_H

#include "opbin.h"

class OpUnion : public OpBin
{
public:
    OpUnion(CSG_Primitive* a, CSG_Primitive* b );

    bool inOut(const glm::vec3 &p) const;
    //bool intersect(const Rayon &r, float &t);
};

#endif // OPUNION_H
