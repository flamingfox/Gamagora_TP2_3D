#include "csg_box.h"

CSG_Box::CSG_Box(const glm::vec3& min, const glm::vec3& max):
    Box(min, max)
{
}

bool CSG_Box::inOut(const vec3& p) const
{
    return Box::inOut(p);
}
