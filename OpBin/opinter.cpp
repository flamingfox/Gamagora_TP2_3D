#include "opinter.h"

OpInter::OpInter(const ObjectCsg &a, const ObjectCsg &b) :
    OpBin(a, b)
{

}

bool OpUnion::InOut(const glm::vec3& p)
{
    if(a.inOut(p) && b.inOut(p))
        return true;

    return false;
}

/*bool OpUnion::intersect(const Rayon& r, float& t)
{
    float tTmp = 0;

    if(a.intersect(r, tTmp) && b.intersect(r, t)){

        if(tTmp < t)
            t = tTmp;

        retour = true;

    }
    return false;
}*/

