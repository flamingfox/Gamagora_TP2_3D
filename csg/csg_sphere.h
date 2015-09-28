#ifndef CSG_SPHERE_H
#define CSG_SPHERE_H

#include "sphere.h"
#include "csg_primitive.h"

class CSG_Sphere : public Sphere, public CSG_Primitive
{
public:
    CSG_Sphere();
    //utilise intersect de Sphere
};

#endif // CSG_SPHERE_H
