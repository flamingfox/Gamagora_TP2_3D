#include "csg/csg_sphere.h"
#include "OpBin/opunion.h"
#include "QDebug"

int main(int argc, char *argv[])
{

    CSG_Sphere* s1 = new CSG_Sphere(glm::vec3(0.f,0.f,0.f), 1.5f);
    CSG_Sphere* s2 = new CSG_Sphere(glm::vec3(2.f,0.f,0.f), 1.5f);

    OpUnion oU(s1, s2);

    qDebug() << "in :" << oU.inOut(glm::vec3(0,0,0));

    qDebug() << "in :" << oU.inOut(glm::vec3(3,0,0));

    qDebug() << "out :" << oU.inOut(glm::vec3(0,3,0));

    qDebug() << "in inter :" << oU.inOut(glm::vec3(1,0,0));

    return 0;
    (void) argc;    (void) argv;
}

