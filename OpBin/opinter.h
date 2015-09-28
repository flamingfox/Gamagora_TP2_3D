#ifndef OPINTER_H
#define OPINTER_H

#include "opbin.h"

class OpInter : public OpBin
{
public:
    OpInter(const CsgObjet& a, const CsgObjet& b );

    bool InOut(const glm::vec3 &p);
    bool intersect(const Rayon &r, float &t);
};

#endif // OPINTER_H
