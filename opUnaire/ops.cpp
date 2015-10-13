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

float OpS::potentiel(const glm::vec3& p) const
{
    return a->potentiel(p/scale);
}

/*bool OpS::intersect(const Rayon &r, float &distanceMin) const
{
    return a->intersect(Rayon(r.getOrigine()/scale, r.getDirection()/scale), distanceMin);
}*/
