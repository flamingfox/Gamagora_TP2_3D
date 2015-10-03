#include "opunaire.h"

OpUnaire::OpUnaire(CSG_Primitive* a):
    a(a)
{
}

OpUnaire::~OpUnaire()
{
    delete a;
}
