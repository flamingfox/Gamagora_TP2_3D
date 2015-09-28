#ifndef CSG_PRIMITIVE_H
#define CSG_PRIMITIVE_H
#include "csg_node.h"

///
/// \author Rudi Welter
/// \brief The CSG_Primitive class
///
class CSG_Primitive : public CSG_Node
{
public:
    CSG_Primitive();
    ~CSG_Primitive();
    virtual bool inOut(glm::vec3 point)=0;
    //virtual bool intersect(Rayon r, float &distance)=0;
};

#endif // CSG_PRIMITIVE_H
