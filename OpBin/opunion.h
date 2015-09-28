#ifndef OPUNION_H
#define OPUNION_H

#include "opbin.h"

class OpUnion : public OpBin
{
public:
    OpUnion(const CsgObjet& a, const CsgObjet& b );

    bool InOut(const glm::vec3 &p);
    //bool intersect(const Rayon &r, float &t);
};

#endif // OPUNION_H
