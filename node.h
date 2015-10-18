#ifndef NODE_H
#define NODE_H
#include "rendu/rayon.h"


/** @brief délimite la distance des hauteurs à calculer autour d'un point pour déterminer sa normale*/
#define RAYON_NORMAL 0.1f

using namespace glm;

///
/// \author Rudi Welter
/// \brief The Node class
///
class Node
{
public:
    Node();
    ~Node();
    virtual bool inOut(const glm::vec3& p) const = 0;
    virtual float potentiel(const glm::vec3& p) const = 0;
    virtual float distance(const glm::vec3& p) const =0;

    //virtual bool intersect(const Rayon& r, float &distance) const =0;

    virtual glm::vec3 getNormal(const vec3& p, float eps = RAYON_NORMAL) const = 0;
};

#endif // NODE_H
