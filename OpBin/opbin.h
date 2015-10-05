#ifndef OPBIN_H
#define OPBIN_H

#include "node.h"

class OpBin : public Node
{
public:
    OpBin(Node* _a, Node* _b);    //info technique: selon le debbugeur, le _a perd sa caractéristique de Sphère (pointeur "Sphere::vprt" inaccessible) quand le _b prend ça valeur. C'est pour ça que j'ai passé en pointeur et pas en adresse.
    ~OpBin();

    virtual bool inOut(const glm::vec3& p) const = 0;
    //virtual bool intersect(const Rayon& r, float &distance) const =0;
    const float distance(const glm::vec3& p) const;

protected:
    Node *a, *b;
};

#endif // OPBIN_H
