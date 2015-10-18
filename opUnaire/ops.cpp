#include "ops.h"


OpS::OpS(Node *a, const glm::vec3& scale):
    OpUnaire(a),   scale(scale)
{
}

glm::vec3 OpS::deplace(const glm::vec3& p) const
{
    return p/scale;
}

/*************************************************************************************/


/*bool OpS::intersect(const Rayon &r, float &distanceMin) const
{
    return a->intersect(Rayon(r.getOrigine()/scale, r.getDirection()/scale), distanceMin);
}*/


vec3 OpS::getNormal(const vec3 &p, float eps) const
{
    return normalize(a->getNormal(deplace(p), eps)*scale);
}
