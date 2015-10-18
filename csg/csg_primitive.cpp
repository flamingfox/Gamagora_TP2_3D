#include "csg_primitive.h"

CSG_Primitive::CSG_Primitive()
{

}

CSG_Primitive::~CSG_Primitive(){

}

float CSG_Primitive::potentiel(const glm::vec3& p) const
{
    return inOut(p) ?   1.f :   0.f;
}
