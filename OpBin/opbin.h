#ifndef OPBIN_H
#define OPBIN_H

#include "csg/csg_primitive.h"

class OpBin
{
public:
    OpBin(CSG_Primitive* _a, CSG_Primitive* _b);    //info technique: selon le debbugeur, le _a perd sa caractéristique de Sphère (pointeur "Sphere::vprt" inaccessible) quand le _b prend ça valeur. C'est pour ça que j'ai passé en pointeur et pas en adresse.
    ~OpBin();

protected:
    CSG_Primitive *a, *b;
};

#endif // OPBIN_H
