#ifndef OPDIF_H
#define OPDIF_H

#include "opbin.h"


class OpDif: public OpBin
{
public:
    OpDif(Node* _a, Node* _b);


    bool inOut(const glm::vec3 &p) const;
    bool inOut(const glm::vec3& p, float& f) const;
    //bool intersect(const Rayon &r, float &t);
};

#endif // OPDIF_H
