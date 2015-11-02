#include <QApplication>
#include "csg/csg_sphere.h"
#include "csg/csg_box.h"
#include "OpBin/opunion.h"
#include "OpBin/opinter.h"
#include "opUnaire/opt.h"
#include "opUnaire/opr.h"
#include "opUnaire/ops.h"
#include "opBin/opdif.h"
#include "node.h"
#include "rendu/scene.h"

#include "si/si_sphere.h"
#include "si/opmelange.h"
#include "si/si_box.h"

#include "terrain/terrainnoise.h"

#include "QDebug"
#include "lib/voxel.h"
#include "rendu/myWindow.h"

#include "export/objmanager.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CSG_Sphere sc1 = CSG_Sphere(glm::vec3(0.f,0.f,0.f), 2.5f);
    CSG_Box bc1 = CSG_Box(glm::vec3(2.f,0.f,0.f), glm::vec3(4.f, 2.f, 2.f));

    OpUnion oUC  = OpUnion(&sc1, &bc1);

    OpT oTC = OpT(&oUC, vec3(0.0,0.0,3.0) );

    SI_Sphere ss1 = SI_Sphere(2.0f, 1.f, 1.5f);
    SI_Sphere ss2 = SI_Sphere(vec3(4,0,0),2.0f, 1.5f, 3.5f);

    ss1.setColor(qRgb(255,50,50));
    ss2.setColor(qRgb(50,255,50));

    opMelange oMS(&ss1, &ss2);

    OpUnion oU = OpUnion(&oTC, &oMS);

    OpR oR = OpR(&oU, vec3(0,0,1), 3.14*1.25);

    OpS node = OpS(&oR, 1.0);


/*
 * test = 0 : Visualisation du voxel sous OpenGL
 * test = 1 : Rendu jpg du lancé de rayons sur SI+CSG+TERRAIN
 * test = 2 : Export du voxel en Mesh (obj)
 */

#define test 1

#if(test == 0)
    const int n = 75;

    Voxel vox(n, &node);

    myWindow myWin; //Ajout de notre classe myWindow
    myWin.vox = vox;
    myWin.show();   //Exécution de notre fenêtre de rendu OpenGL
    std::cout << "+ , - = speed"<<std::endl<<"z , s = zoom"<<std::endl<<"Up, Down = hauteur objet";

    return app.exec();

#elif(test == 1)
    Scene scene;

    TerrainNoise* terre = new TerrainNoise(1000,1000);

    scene.setNode(new OpUnion(&node, new OpT(terre,vec3(-500,-500,-170))));

    scene.addC(new Camera(vec3(10,-10,0), vec3(0,0,2), 200,720,400));

    scene.rendu();

    delete terre;
    return 0;

#elif(test == 2)

    const int n = 50;

    Voxel vox(n, &node);

    ObjManager::voxelSave("./test.obj", vox);

    return 0;

#endif

    (void) argc;    (void) argv;

}

