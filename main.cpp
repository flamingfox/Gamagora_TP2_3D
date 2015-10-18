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

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    //CSG_Sphere* s1 = new CSG_Sphere(glm::vec3(0.f,0.f,0.f), 1.5f);
    //CSG_Sphere* s2 = new CSG_Sphere(glm::vec3(2.f,0.f,0.f), 1.5f);
    //CSG_Box* b1 = new CSG_Box(vec3(0,-3,3.5), vec3(4,2,6));

    SI_Box* b1 = new SI_Box(vec3(0,-3,3.5), vec3(4,2,6), 0.75f,2.0f);
    SI_Sphere* s1 = new SI_Sphere(2.0f, 1.f, 1.5f);
    SI_Sphere* s2 = new SI_Sphere(vec3(4,0,0),2.0f, 1.5f, 3.5f);

    //TerrainNoise* terre = new TerrainNoise(1000,1000);


    opMelange oU(s1, s2);
    oU.addPrim(b1);

    OpR oR(&oU, glm::normalize(glm::vec3(0,0,1)), 3.14f*0.25);

    OpS* node = new OpS(&oR, vec3(0.3,0.3,0.3));

    qDebug() << "in :" << oR.inOut(glm::vec3(0,0,0));

    qDebug() << "out :" << oR.inOut(glm::vec3(3,0,0));



#if 1
    const int nb = 50;
    Voxel vox(nb);
    for(float i=0; i<nb; i++){
        for(float j=0; j<nb; j++){
            for(float k=0; k<nb; k++){
                if(node->inOut(glm::vec3(-1.5+(i/10.0),-1.5+(j/10.),-1.5+(k/10.))))
                {
                    vox(i,j,k)=1;
                }
                else vox(i,j,k)=0;
            }
        }
    }

    myWindow myWin; //Ajout de notre classe myWindow
    myWin.vox = vox;
    myWin.show();   //Exécution de notre fenêtre de rendu OpenGL

    delete s1;    delete s2; delete node;
    return app.exec();

#else
    Scene scene;
    scene.setNode(node);//new OpUnion(b1,&oR));//
    //scene.setNode(new OpR(s1,vec3(0,0,1),2.0));//
    scene.addC(new Camera(glm::vec3(2.5,-7,0), glm::vec3(0,0,2),200,720,400));
    scene.rendu();

    delete s1;    delete s2;    delete node;
    return 0;

    (void) argc;    (void) argv;

#endif

}

