#include "csg/csg_sphere.h"
#include "csg/csg_box.h"
#include "OpBin/opunion.h"
#include "OpBin/opinter.h"
#include "opUnaire/opt.h"
#include "opUnaire/opr.h"

#include "QDebug"

int main(int argc, char *argv[])
{

    CSG_Box* s1 = new CSG_Box(3.f);
    CSG_Box* s2 = new CSG_Box(3.f);

    OpT t(s2, glm::vec3(2,0,0));

    OpUnion oU(s1, &t);

    OpR oR(&oU, glm::vec3(0,0,1), 3.14f/2);

    qDebug() << "in :" << oR.inOut(glm::vec3(0,0,0));

    qDebug() << "out :" << oR.inOut(glm::vec3(3,0,0));

    qDebug() << "in :" << oR.inOut(glm::vec3(0,3,0));

    qDebug() << "in inter :" << oR.inOut(glm::vec3(0,1,0));

    return 0;
    (void) argc;    (void) argv;
}

