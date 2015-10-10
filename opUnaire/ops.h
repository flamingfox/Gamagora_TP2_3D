#ifndef OPS_H
#define OPS_H

#include "opunaire.h"
#include "csg/csg_primitive.h"


class OpS: public OpUnaire
{
public:
    OpS(Node* a, const glm::vec3& scale);

    bool inOut(const glm::vec3 &p) const;
    bool inOut(const glm::vec3& p, float& f) const;
    //bool intersect(const Rayon &r, float &distanceMin) const;
private:
    glm::vec3 scale;
};


#endif // OPS_H
