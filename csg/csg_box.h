#ifndef CSG_BOX_H
#define CSG_BOX_H

#include "lib/box.h"
#include "csg_primitive.h"


class CSG_Box : public CSG_Primitive,  public Box
{
public:
    CSG_Box(float cote);
    bool inOut(const vec3& point) const;

    bool intersect(const Rayon &r, float &distanceMin) const;

private:
    float cote;
};

#endif // CSG_BOX_H
