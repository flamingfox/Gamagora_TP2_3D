#include <QApplication>
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

#include "terrain/terrainnoise.h"

#include "QDebug"
#include "lib/voxel.h"
#include "rendu/myWindow.h"

#include "export/objmanager.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CSG_Sphere* s1 = new CSG_Sphere(glm::vec3(0.f,0.f,0.f), 1.5f);
    CSG_Sphere* s2 = new CSG_Sphere(glm::vec3(2.f,0.f,0.f), 1.5f);

    //CSG_Box c1(1.0);


    opMelange oU(s1, s2);

    OpR oR(&oU, glm::normalize(glm::vec3(0,0,1)), 3.14f*0.25);

    qDebug() << "in :" << oR.inOut(glm::vec3(0,0,0));

    qDebug() << "out :" << oR.inOut(glm::vec3(3,0,0));

    int n = 50;

    Voxel vox(n);
    for(float i=0; i<n; i++){
        for(float j=0; j<n; j++){
            for(float k=0; k<n; k++){
                if(oU.inOut(glm::vec3(-1.5+(i/10.0),-1.5+(j/10.),-1.5+(k/10.))))
                {
                    vox(i,j,k)=1;
                }
                else vox(i,j,k)=0;
            }
        }
    }

    ObjManager::voxelSave("test.obj", vox);

    myWindow myWin; //Ajout de notre classe myWindow
    myWin.vox = vox;
    myWin.show();   //Exécution de notre fenêtre de rendu OpenGL
    return app.exec();

    (void) argc;    (void) argv;
}

