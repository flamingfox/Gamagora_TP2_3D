#include "ops.h"


OpS::OpS(CSG_Primitive* a, const glm::vec3& scale):
    OpUnaire(a),   scale(scale)
{
}

/*************************************************************************************/

bool OpS::inOut(const glm::vec3 &p) const
{
    return a->inOut(p*(-scale));
}
