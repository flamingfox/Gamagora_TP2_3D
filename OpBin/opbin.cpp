#include "opbin.h"

OpBin::OpBin(Node* _a, Node* _b) :
    a(_a), b(_b)
{

}

OpBin::~OpBin()
{
    //delete a;
    //delete b;
}

float OpBin::distance(const glm::vec3 &p) const
{
    if(a->distance(p) < b->distance(p))
        return a->distance(p);
    else
        return b->distance(p);
}
