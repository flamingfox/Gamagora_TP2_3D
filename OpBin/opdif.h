#ifndef OPDIF_H
#define OPDIF_H

#include "opbin.h"


class OpDif: public OpBin
{
public:
    OpDif(CSG_Primitive* _a, CSG_Primitive* _b);


    bool inOut(const glm::vec3 &p) const;
    //bool intersect(const Rayon &r, float &t);
};

#endif // OPDIF_H
