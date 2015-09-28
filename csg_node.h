#ifndef CSG_NODE_H
#define CSG_NODE_H
#include "rayon.h"

///
/// \author Rudi Welter
/// \brief The CSG_Node class
///
class CSG_Node
{
public:
    CSG_Node();
    ~CSG_Node();
    virtual bool inOut(glm::vec3 point)=0;
    virtual bool intersect(Rayon r, float &distance)=0;
};

#endif // CSG_NODE_H
