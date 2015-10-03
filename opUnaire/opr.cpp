#include "opr.h"

OpR::OpR(CSG_Primitive* a, const glm::vec3 &centre, const glm::vec3& axe, float angle):
    OpUnaire(a),   centre(centre), axe(axe),   angle(angle)
{
}

/*************************************************************************************/

bool OpR::inOut(const glm::vec3 &p) const
{
    glm::vec3 v = p-centre;

    if(angle != 0)
    {
        //axe2 = glm::normalize(axe);
        float x = v.x, y = v.y; //pour ne pas prendre la valeure modifiée dans les lignes suivantes (v.z = ...)

        v.x =   axe.x*(axe.x*x + axe.y*y + axe.z*v.z) * (1-cos(-angle))+
                x*cos(-angle)+
                (-axe.z*y + axe.y*v.z) * sin(-angle);
        v.y =   axe.y*(axe.x*x + axe.y*y + axe.z*v.z) * (1-cos(-angle))+
                y*cos(-angle)+
                (axe.z*x - axe.x*v.z) * sin(-angle);
        v.z =   axe.z*(axe.x*x + axe.y*y + axe.z*v.z) * (1-cos(-angle))+
                v.z*cos(-angle)+
                (-axe.y*x + axe.x*y) * sin(-angle);
    }
    return a->inOut(v);
}
