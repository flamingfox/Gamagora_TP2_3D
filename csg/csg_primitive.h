#ifndef CSG_PRIMITIVE_H
#define CSG_PRIMITIVE_H
#include "node.h"

///
/// \author Rudi Welter
/// \brief The CSG_Primitive class
///
class CSG_Primitive : public Node
{
public:
    CSG_Primitive();
    ~CSG_Primitive();
    virtual bool inOut(const glm::vec3& point) const = 0;
    //virtual bool intersect(Rayon r, float &distance)=0;
};

#endif // CSG_PRIMITIVE_H
