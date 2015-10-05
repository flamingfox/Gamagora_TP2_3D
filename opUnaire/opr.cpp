#include "opr.h"

OpR::OpR(Node *a, const glm::vec3& axe, float angle):
    OpUnaire(a),   axe(axe),   angle(angle)
{
}

/*************************************************************************************/

bool OpR::inOut(const glm::vec3 &p) const
{
    glm::vec3 v = p;
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


/*bool OpR::intersect(const Rayon &r, float &distanceMin) const
{
    glm::vec3   o = r.getOrigine(),
                d = r.getDirection();

    if(angle != 0)
    {
        //axe2 = glm::normalize(axe);
        float x = o.x, y = o.y; //pour ne pas prendre la valeure modifiée dans les lignes suivantes (v.z = ...)

        o.x =   axe.x*(axe.x*x + axe.y*y + axe.z*o.z) * (1-cos(-angle))+
                x*cos(-angle)+
                (-axe.z*y + axe.y*o.z) * sin(-angle);
        o.y =   axe.y*(axe.x*x + axe.y*y + axe.z*o.z) * (1-cos(-angle))+
                y*cos(-angle)+
                (axe.z*x - axe.x*o.z) * sin(-angle);
        o.z =   axe.z*(axe.x*x + axe.y*y + axe.z*o.z) * (1-cos(-angle))+
                o.z*cos(-angle)+
                (-axe.y*x + axe.x*y) * sin(-angle);

        x = d.x, y = d.y;

        d.x =   axe.x*(axe.x*x + axe.y*y + axe.z*d.z) * (1-cos(-angle))+
                x*cos(-angle)+
                (-axe.z*y + axe.y*d.z) * sin(-angle);
        d.y =   axe.y*(axe.x*x + axe.y*y + axe.z*d.z) * (1-cos(-angle))+
                y*cos(-angle)+
                (axe.z*x - axe.x*d.z) * sin(-angle);
        d.z =   axe.z*(axe.x*x + axe.y*y + axe.z*d.z) * (1-cos(-angle))+
                d.z*cos(-angle)+
                (-axe.y*x + axe.x*y) * sin(-angle);
    }

    return a->intersect(Rayon(o,d), distanceMin);
}*/
