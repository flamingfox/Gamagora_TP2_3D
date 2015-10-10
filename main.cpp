#include "csg/csg_sphere.h"
#include "csg/csg_box.h"
#include "OpBin/opunion.h"
#include "OpBin/opinter.h"
#include "opUnaire/opt.h"
#include "opUnaire/opr.h"
#include "opBin/opdif.h"
#include "node.h"
#include "rendu/scene.h"

#include "si/si_sphere.h"

#include "QDebug"

int main(int argc, char *argv[])
{

    SI_Sphere* s1 = new SI_Sphere(2.0f, 4.0f);
    SI_Sphere* s2 = new SI_Sphere(2.0f, 4.0f);
    //CSG_Sphere* s1 = new CSG_Sphere(2.f);
    //CSG_Sphere* s2 = new CSG_Sphere(1.5f);

    OpT t(s2, glm::vec3(5.0,0,0));

    OpUnion oU(s1, &t);

    OpR oR(&oU, glm::normalize(glm::vec3(0,0,1)), 3.14f*0);

    /*qDebug() << "in :" << oR.inOut(glm::vec3(0,0,0));

    qDebug() << "out :" << oR.inOut(glm::vec3(3,0,0));

    qDebug() << "in :" << oR.inOut(glm::vec3(0,3,0));

    qDebug() << "in inter :" << oR.inOut(glm::vec3(0,1,0));*/

    Scene scene;
    scene.setNode(&oR);
    scene.addC(new Camera(glm::vec3(2.5,-5,0), glm::vec3(2.5,0,0),200,720,400));
    scene.rendu();

    delete s1;    delete s2;
    return 0;

    (void) argc;    (void) argv;
}

