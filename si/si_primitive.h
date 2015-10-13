#ifndef SI_PRIMITIVE_H
#define SI_PRIMITIVE_H

#include "node.h"
#include "lib/interpolation.h"

class SI_Primitive : public Node
{
public:
    SI_Primitive();

    bool inOut(const glm::vec3& p) const;
    virtual float potentiel(const glm::vec3& p) const = 0;
    //virtual bool intersect(const Rayon& r, float &distance) const = 0;
    virtual float distance(const glm::vec3& p) const =0;
};

#endif // SI_PRIMITIVE_H
