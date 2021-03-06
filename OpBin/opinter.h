#ifndef OPINTER_H
#define OPINTER_H

#include "opbin.h"

class OpInter : public OpBin
{
public:
    OpInter(Node* a, Node* b );

    bool inOut(const glm::vec3 &p) const;
    float potentiel(const glm::vec3& p) const;
    float distance(const glm::vec3 &p) const;
    //bool intersect(const Rayon &r, float &t);

    vec3 getNormal(const vec3& p, float eps = RAYON_NORMAL) const;
    QRgb getColor(const vec3& p) const;

    Box getBox() const;

};

#endif // OPINTER_H
