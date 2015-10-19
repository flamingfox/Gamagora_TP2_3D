#include "node.h"

Node::Node()
{
    box = Box(vec3(-1.5,-1.5,-1.5),vec3(1.5,1.5,1.5));
}

Node::~Node(){

}



QRgb Node::getColor(const vec3& p) const
{
    return DEFAULT_COLOR;
    (void) p;
}
