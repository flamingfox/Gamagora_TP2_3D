#include <QApplication>
#include "csg/csg_sphere.h"
#include "OpBin/opunion.h"
#include "QDebug"
#include "lib/voxel.h"
#include "rendu/myWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CSG_Sphere* s1 = new CSG_Sphere(glm::vec3(0.f,0.f,0.f), 1.5f);
    CSG_Sphere* s2 = new CSG_Sphere(glm::vec3(2.f,0.f,0.f), 1.5f);

    OpUnion oU(s1, s2);

    qDebug() << "in :" << oU.inOut(glm::vec3(0,0,0));

    qDebug() << "in :" << oU.inOut(glm::vec3(3,0,0));

    qDebug() << "out :" << oU.inOut(glm::vec3(0,3,0));

    qDebug() << "in inter :" << oU.inOut(glm::vec3(1,0,0));

    Voxel vox(50);
    for(float i=0; i<50; i++){
        for(float j=0; j<50; j++){
            for(float k=0; k<50; k++){
                if(oU.inOut(glm::vec3(-1.5+(i/10.0),-1.5+(j/10.),-1.5+(k/10.))))
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
    return app.exec();

    (void) argc;    (void) argv;
}

