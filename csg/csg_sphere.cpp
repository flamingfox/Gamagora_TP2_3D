#include "csg/csg_sphere.h"

CSG_Sphere::CSG_Sphere(const glm::vec3 &c, float r):
    Sphere(c, r)
{
}

bool CSG_Sphere::inOut(vec3 point)
{
    return Sphere::inOut(point);
}
