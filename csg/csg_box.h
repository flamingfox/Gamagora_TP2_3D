#ifndef CSG_BOX_H
#define CSG_BOX_H

#include "box.h"
#include "csg_primitive.h"


class CSG_Box : public CSG_Primitive,  public Box
{
public:
    CSG_Box(const glm::vec3& min, const glm::vec3& max);
    bool inOut(const vec3& point) const;
};

#endif // CSG_BOX_H
