#include "opbin.h"

OpBin::OpBin(CSG_Primitive* _a, CSG_Primitive* _b) :
    a(_a), b(_b)
{

}

OpBin::~OpBin()
{
    delete a;
    delete b;
}
