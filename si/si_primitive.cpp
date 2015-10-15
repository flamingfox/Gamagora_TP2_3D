#include "si_primitive.h"

SI_Primitive::SI_Primitive()
{
}


SI_Primitive::SI_Primitive(float e, float R):
        e(e), R(R)
{
}

bool SI_Primitive::inOut(const glm::vec3 &p) const
{
    return potentiel(p) >= 0.5f;
}


// Smooth falloff function
// r : small radius
// R : Large radius
float SI_Primitive::falloff( float r, float R ) const //fonction G du cours
{
  float x = glm::clamp(r/R,0.f,1.f);
  float y = (1.f-x*x);
  return y*y*y;
}
