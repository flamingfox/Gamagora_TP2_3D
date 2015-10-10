#include "ops.h"


OpS::OpS(Node *a, const glm::vec3& scale):
    OpUnaire(a),   scale(scale)
{
}

/*************************************************************************************/

bool OpS::inOut(const glm::vec3 &p) const
{
    return a->inOut(p/scale);
}

bool OpS::inOut(const glm::vec3& p, float& f) const
{
    return a->inOut(p/scale, f);
}

/*bool OpS::intersect(const Rayon &r, float &distanceMin) const
{
    return a->intersect(Rayon(r.getOrigine()/scale, r.getDirection()/scale), distanceMin);
}*/
