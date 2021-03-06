#include "ops.h"


OpS::OpS(Node *a, const glm::vec3& scale):
    OpUnaire(a),   scale(scale)
{
}
OpS::OpS(Node *a, float scale):
    OpS(a, vec3(scale,scale,scale))
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

float OpS::distance(const glm::vec3 &p) const
{
    return scale.x * a->distance(deplace(p));
    //a revoir; marche quand le redimensionnement x==y==z
}

Box OpS::getBox() const
{
    Box box = a->getBox();
    return Box(box.getMin()*scale, box.getMax()*scale);
}
