#include "csg_box.h"

CSG_Box::CSG_Box(float cote):
    Box(glm::vec3(-cote/2,-cote/2,-cote/2), glm::vec3(cote/2,cote/2,cote/2))
{
}

CSG_Box::CSG_Box(const vec3& _min, const vec3& _max)    :
    Box(_min,_max)
{
}

bool CSG_Box::inOut(const vec3& p) const
{
    return Box::inOut(p);
}

bool CSG_Box::intersect(const Rayon &r, float &distanceMin) const
{
    float distanceMax;
    return Box::intersect(r, distanceMin, distanceMax);
}
