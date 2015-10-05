#ifndef OPINTER_H
#define OPINTER_H

#include "opbin.h"

class OpInter : public OpBin
{
public:
    OpInter(Node* a, Node* b );

    bool inOut(const glm::vec3 &p) const;
    //bool intersect(const Rayon &r, float &t);
};

#endif // OPINTER_H
