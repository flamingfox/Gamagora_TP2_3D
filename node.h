#ifndef NODE_H
#define NODE_H
#include "rendu/rayon.h"

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
    virtual bool inOut(const glm::vec3& p, float& f) const = 0;
    virtual float distance(const glm::vec3& p) const =0;
    //virtual bool intersect(const Rayon& r, float &distance) const =0;
};

#endif // NODE_H
