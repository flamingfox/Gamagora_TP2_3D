#ifndef OPT_H
#define OPT_H

#include "opunaire.h"
#include "csg/csg_primitive.h"


class OpT: public OpUnaire
{
public:
    OpT(CSG_Primitive* a, const glm::vec3& tranlate);

    bool inOut(const glm::vec3 &p) const;
private:
    glm::vec3 trans;
};


#endif // OPT_H
