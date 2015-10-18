#include "node.h"

Node::Node()
{

}

Node::~Node(){

}


glm::vec3 Node::getNormal(const vec3& p, float eps) const
{
  float v = potentiel(p);
  glm::vec3 n(  potentiel( glm::vec3(p.x+eps, p.y, p.z) ) - v,
                potentiel( glm::vec3(p.x, p.y+eps, p.z) ) - v,
                potentiel( glm::vec3(p.x, p.y, p.z+eps) ) - v);
  return normalize(n);
}
