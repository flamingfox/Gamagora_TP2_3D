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

bool OpT::intersect(const Rayon &r, float &distanceMin) const
{
    return a->intersect(Rayon(r.getOrigine()-trans, r.getDirection()), distanceMin);
}