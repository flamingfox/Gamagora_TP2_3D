#ifndef CSG_BOX_H
#define CSG_BOX_H

#include "box.h"
#include "csg_primitive.h"


class CSG_Box : public CSG_Primitive,  public Box
{
public:
    CSG_Box(float cote);
    CSG_Box(const vec3& _min, const vec3& _max);
    bool inOut(const vec3& point) const;
    bool intersect(const Rayon &r, float &distanceMin) const;

private:
};

#endif // CSG_BOX_H
