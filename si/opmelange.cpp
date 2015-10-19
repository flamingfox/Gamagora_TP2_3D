#include "opmelange.h"

opMelange::opMelange()
{
}

opMelange::opMelange(Node* prim)
{
    primitives.push_back(prim);
}
opMelange::opMelange(Node* a, Node* b)
{
    primitives.push_back(a);
    primitives.push_back(b);
}

opMelange::opMelange(std::vector<Node*> prims)
{
    primitives = prims;
}

/**********************************************************************/

opMelange* opMelange::addPrim(Node* prim)
{
    primitives.push_back(prim);
    return this;
}

/**********************************************************************/

bool opMelange::inOut(const vec3 &p) const
{
    return potentiel(p) >= DEFAULT_T;
}


float opMelange::potentiel(const glm::vec3& p) const
{
    float f = 0.f;
    for(const Node* prim : primitives)
        f += prim->potentiel(p);

    return f;
}
float opMelange::distance(const glm::vec3& p) const
{
    float min = FLT_MAX;
    for(const Node* prim : primitives)  {
        float d = prim->distance(p);
        if(d < min)
            min = d;
    }
    return min;
}

glm::vec3 opMelange::getNormal(const vec3& p, float eps) const
{
  float v = potentiel(p);
  glm::vec3 n(  potentiel( glm::vec3(p.x+eps, p.y, p.z) ) - v,
                potentiel( glm::vec3(p.x, p.y+eps, p.z) ) - v,
                potentiel( glm::vec3(p.x, p.y, p.z+eps) ) - v);
  n -= vec3(potentiel( glm::vec3(p.x-eps, p.y, p.z) ) - v,
            potentiel( glm::vec3(p.x, p.y-eps, p.z) ) - v,
            potentiel( glm::vec3(p.x, p.y, p.z-eps) ) - v);
  return -normalize(n);
}


void opMelange::setColor(const QRgb& color)
{
    for(Node* prim : primitives)
        prim->setColor(color);
}

//#include <QColor>
QRgb opMelange::getColor(const vec3& p) const
{
    QRgb color = qRgb(0,0,0);
    //float somme;
    for(const Node* prim : primitives)
    {
        //float e = prim->potentiel(p);
        QRgb c = prim->getColor(p);
        //QColor col(c);
        color = qRgb(std::min(qRed(color)+qRed(c),255),std::min(qGreen(color)+qGreen(c),255),std::min(qBlue(color)+qBlue(c),255));
    }
    return color;//somme;
}
