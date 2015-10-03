#ifndef OPUNAIRE_H
#define OPUNAIRE_H

#include "node.h"
#include "csg/csg_primitive.h"


class OpUnaire : public Node
{
public:
    OpUnaire(CSG_Primitive* a);
    ~OpUnaire();

    virtual bool inOut(const glm::vec3 &p) const = 0;
protected:
    CSG_Primitive* a;   //à remplacer par une Node* pour la suite
};


#endif // OPUNAIRE_H
