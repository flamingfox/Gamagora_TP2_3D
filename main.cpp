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
#include "si/opmelange.h"
#include "si/si_box.h"

#include "QDebug"

int main(int argc, char *argv[])
{

    //SI_Box* b2 = new SI_Box(3.0f, 2.f,0.5f);
    SI_Sphere* s1 = new SI_Sphere(2.0f, 1.f, 1.5f);
    SI_Sphere* s2 = new SI_Sphere(2.0f, 1.5f, 3.5f);

    SI_Box* b1 = new SI_Box(vec3(0,-3,3.5), vec3(4,2,6), 1.0f,1.0f);
    //CSG_Sphere* s1 = new CSG_Sphere(2.f);
    //CSG_Sphere* s2 = new CSG_Sphere(1.5f);

    //float min, max;
    //s1->intersect(Rayon(vec3(3,0,4.1),vec3(-1,0,0)), min, max);
    //std::cout << min << " / " << max << std::endl;
    OpT t(s2, glm::vec3(5.0,0,0));


    opMelange oU(s1, &t);
    oU.addPrim(b1);

    OpR oR(&oU, glm::normalize(glm::vec3(0,0,1)), 3.14f*0.25);

    /*qDebug() << "in :" << oR.inOut(glm::vec3(0,0,0));

    qDebug() << "out :" << oR.inOut(glm::vec3(3,0,0));

    qDebug() << "in :" << oR.inOut(glm::vec3(0,3,0));

    qDebug() << "in inter :" << oR.inOut(glm::vec3(0,1,0));*/

    Scene scene;
    scene.setNode(&oR);
    scene.addC(new Camera(glm::vec3(2.5,-7,0), glm::vec3(0,0,2),200,720,400));
    scene.rendu();

    delete s1;    delete s2;
    return 0;

    (void) argc;    (void) argv;
}

