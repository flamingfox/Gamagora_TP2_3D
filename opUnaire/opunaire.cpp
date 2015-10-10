#include "opunaire.h"

OpUnaire::OpUnaire(Node *a):
    a(a)
{
}

OpUnaire::~OpUnaire()
{
    //delete a;
}

float OpUnaire::distance(const glm::vec3 &p) const
{
    return a->distance(p);
}



