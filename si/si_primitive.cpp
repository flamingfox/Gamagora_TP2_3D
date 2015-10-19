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
    return potentiel(p) >= DEFAULT_T;
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

vec3 SI_Primitive::getNormal(const vec3& p, float eps) const
{
  float v = potentiel(p);
  glm::vec3 n(  potentiel( glm::vec3(p.x+eps, p.y, p.z) ) - v,
                potentiel( glm::vec3(p.x, p.y+eps, p.z) ) - v,
                potentiel( glm::vec3(p.x, p.y, p.z+eps) ) - v);
  n -= vec3(potentiel( glm::vec3(p.x-eps, p.y, p.z) ) - v,
            potentiel( glm::vec3(p.x, p.y-eps, p.z) ) - v,
            potentiel( glm::vec3(p.x, p.y, p.z-eps) ) - v);
  return -normalize(n);
}


void SI_Primitive::setColor(const QRgb& color)
{
    this->color = color;
}

QRgb SI_Primitive::getColor(const vec3& p) const
{
    float e1 = potentiel(p)/DEFAULT_T;
    return qRgb(std::min(qRed(color)*e1,255.f),std::min(qGreen(color)*e1,255.f),std::min(qBlue(color)*e1,255.f));
    (void) p;
}
