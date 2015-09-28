#ifndef CSG_SPHERE_H
#define CSG_SPHERE_H

#include "sphere.h"
#include "csg_primitive.h"

class CSG_Sphere : public CSG_Primitive,  public Sphere
{
public:
    CSG_Sphere(const glm::vec3 &c, float r);
    bool inOut(vec3 point);
};

#endif // CSG_SPHERE_H
