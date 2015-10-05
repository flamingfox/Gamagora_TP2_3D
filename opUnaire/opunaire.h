#ifndef OPUNAIRE_H
#define OPUNAIRE_H

#include "node.h"
#include "csg/csg_primitive.h"


class OpUnaire : public Node
{
public:
    OpUnaire(Node* a);
    ~OpUnaire();

    virtual bool inOut(const glm::vec3 &p) const = 0;
    //virtual bool intersect(const Rayon &r, float &distanceMin) const = 0;
    const float distance(const glm::vec3& p) const;
protected:
    Node* a;   //à remplacer par une Node* pour la suite
};


#endif // OPUNAIRE_H
