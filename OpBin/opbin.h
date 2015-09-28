#ifndef OPBIN_H
#define OPBIN_H

#include "csg/csg_primitive.h"

class OpBin
{
public:
    OpBin(CSG_Primitive& _a, CSG_Primitive& _b);
    ~OpBin();

protected:
    CSG_Primitive *a, *b;
};

#endif // OPBIN_H
