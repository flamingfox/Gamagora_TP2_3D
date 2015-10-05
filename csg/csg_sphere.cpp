#include "csg/csg_sphere.h"

CSG_Sphere::CSG_Sphere(float r):
    Sphere(glm::vec3(0,0,0), r)
{
}

CSG_Sphere::CSG_Sphere(const glm::vec3 &c, float r):
    Sphere(c, r)
{
}


bool CSG_Sphere::inOut(const vec3& point) const
{
    return Sphere::inOut(point);
}

bool CSG_Sphere::intersect(const Rayon &r, float &distanceMin) const
{
    float distanceMax;
    return Sphere::intersect(r, distanceMin, distanceMax);
}

const float CSG_Sphere::distance(const vec3 &p) const
{
    float dst = glm::distance(p, centre) - rayon;

    if(dst > 0)
        return dst;
    else
        return 0;
}
