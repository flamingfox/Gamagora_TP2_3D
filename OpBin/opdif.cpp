#include "opdif.h"


OpDif::OpDif(Node *_a, Node *_b):
    OpBin(_a, _b)
{
}

bool OpDif::inOut(const glm::vec3 &p) const
{
    return (a->inOut(p) && !b->inOut(p));
}

float OpDif::potentiel(const glm::vec3& p) const
{
    return a->potentiel(p) - b->potentiel(p);
}

float OpDif::distance(const glm::vec3 &p) const
{
    //algorithme à retrouver à partir de la fin de l'intersection
    return std::min(a->distance(p), b->distance(p));
}
