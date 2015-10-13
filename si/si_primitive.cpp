#include "si_primitive.h"

SI_Primitive::SI_Primitive()
{
}

bool SI_Primitive::inOut(const glm::vec3 &p) const
{
    return potentiel(p) >= 1.f;
}

