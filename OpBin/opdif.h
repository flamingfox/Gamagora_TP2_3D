#ifndef OPDIF_H
#define OPDIF_H

#include "opbin.h"


class OpDif: public OpBin
{
public:
    OpDif(Node* _a, Node* _b);


    bool inOut(const glm::vec3 &p) const;
    float potentiel(const glm::vec3& p) const;
    float distance(const glm::vec3 &p) const;
    //bool intersect(const Rayon &r, float &t);
};

#endif // OPDIF_H
