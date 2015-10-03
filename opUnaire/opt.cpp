#include "opUnaire/opt.h"

OpT::OpT(CSG_Primitive* a, const glm::vec3& translate):
    OpUnaire(a),   trans(translate)
{
}

/*************************************************************************************/

bool OpT::inOut(const glm::vec3 &p) const
{
    return a->inOut(p-trans);
}
