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
    /*CSG_Sphere* s1 = new CSG_Sphere(glm::vec3(0.f,0.f,0.f), 1.5f);
    CSG_Sphere* s2 = new CSG_Sphere(glm::vec3(2.f,0.f,0.f), 1.5f);
    CSG_Box* b1 = new CSG_Box(vec3(0,-3,3.5), vec3(4,2,6));*/

    SI_Box* b1 = new SI_Box(vec3(0,-3,3.5), vec3(4,2,6), 0.75f,2.0f);
    SI_Sphere* s1 = new SI_Sphere(2.0f, 1.f, 1.5f);
    SI_Sphere* s2 = new SI_Sphere(vec3(4,0,0),2.0f, 1.5f, 3.5f);


    b1->setColor(qRgb(50,50,255));
    s1->setColor(qRgb(255,50,50));
    s2->setColor(qRgb(50,255,50));

    //CSG_Box c1(1.0);

    opMelange oU(s1, s2);
    oU.addPrim(b1);

    OpR oR(&oU, glm::normalize(glm::vec3(0,0,1)), 3.14f*0.25);

    OpS* node = new OpS(&oR, 1.0);

    qDebug() << "in :" << oR.inOut(glm::vec3(0,0,0));

    qDebug() << "out :" << oR.inOut(glm::vec3(3,0,0));


#if 0
    const int n = 50;

    Voxel vox(n,node);
    /*
    for(float i=0; i<n; i++){
        for(float j=0; j<n; j++){
            for(float k=0; k<n; k++){
                if(node->inOut(glm::vec3(-1.5+(i/10.0),-1.5+(j/10.),-1.5+(k/10.))))
                {
                    vox(i,j,k)=1;
                }
                else vox(i,j,k)=0;
            }
        }
    }*/

    ObjManager::voxelSave("./test.obj", vox);

    myWindow myWin; //Ajout de notre classe myWindow
    myWin.vox = vox;
    myWin.show();   //Exécution de notre fenêtre de rendu OpenGL

    delete s1;    delete s2; delete node;
    return app.exec();

#else
    CSG_Box* box = new CSG_Box(node->getBox());
    Scene scene;
    //scene.setNode(new OpS(b1,0.5));//new OpUnion(b1,&oR));//
    //scene.setNode(new OpR(s1,vec3(0,0,1),2.0));//

    TerrainNoise* terre = new TerrainNoise(1000,1000);
    //scene.setNode(new OpUnion(box,new OpUnion(node, new OpT(terre,vec3(-500,-500,-170)))));
    scene.setNode(new OpUnion(node, new OpT(terre,vec3(-500,-500,-170))));

    //scene.setNode(node);
    scene.addC(new Camera(vec3(10,-10,0), vec3(0,0,2), 200,720,400));
    //scene.addC(new Camera(vec3(-10,-10,10), vec3(500,500,-300), 200,720,400));
    scene.rendu();

    delete s1;    delete s2;    delete node;
    return 0;

    (void) argc;    (void) argv;

#endif

}

