#include "objmanager.h"

namespace ObjManager {

void voxelSave(const std::string name, const Voxel &vox)
{
    std::vector<glm::vec3> vertex;
    vertex.reserve(vox.get_n()*vox.get_n()*vox.get_n());
    std::vector<unsigned int> face;

    /*
          (s7)       (s6)
           x----------x
          /          /|
     (s3)/      (s2)/ |
        x----------x  |
        |          |  |
        |  x       |  x (s5)
        | (s4)     | /
        |          |/
        x----------x
      (s0)        (s1)


      v.at(i*_n*_n+j*_n+k)

    */

    const unsigned int nb = vox.get_n();
    for(unsigned int i=0; i<nb; i++){
        for(unsigned int j=0; j<nb; j++){
            for(unsigned int k=0; k<nb; k++){
                // ajout vertex
                vertex.push_back(glm::vec3(i,j,k));
            }
        }
    }

    for(unsigned int i=0; i<nb-1; i++){
        for(unsigned int j=0; j<nb-1; j++){
            for(unsigned int k=0; k<nb-1; k++){

                // ajout faces
                unsigned int s0 = vox(i,j,k), s1 = vox(i,j,k+1), s2 = vox(i,j+1,k+1), s3 = vox(i,j+1,k),
                        s4 = vox(i+1,j,k), s5 = vox(i+1,j,k+1), s6 = vox(i+1,j+1,k+1), s7 = vox(i+1,j+1,k);

                unsigned int indS0 = i*vox.get_n()*vox.get_n() + j*vox.get_n()+ k,
                        indS1 = i*vox.get_n()*vox.get_n() + j*vox.get_n()+ k+1,
                        indS2 = i*vox.get_n()*vox.get_n() + (j+1)*vox.get_n()+ k+1,
                        indS3 = i*vox.get_n()*vox.get_n() + (j+1)*vox.get_n()+ k,
                        indS4 = (i+1)*vox.get_n()*vox.get_n() + j*vox.get_n()+ k,
                        indS5 = (i+1)*vox.get_n()*vox.get_n() + j*vox.get_n()+ k+1,
                        indS6 = (i+1)*vox.get_n()*vox.get_n() + (j+1)*vox.get_n()+ k+1,
                        indS7 = (i+1)*vox.get_n()*vox.get_n() + (j+1)*vox.get_n()+ k;


                //** Face s0,s1,s2,s3 **//
                if( s0 != 0 ){
                    if( s1 != 0 ){
                        if( s2 != 0 ){
                            face.push_back(indS0);
                            face.push_back(indS1);
                            face.push_back(indS2);
                        }
                        else if( s3 != 0){
                            face.push_back(indS0);
                            face.push_back(indS1);
                            face.push_back(indS3);
                        }
                    }

                    if(s2 !=0 && s3 != 0){
                        face.push_back(indS0);
                        face.push_back(indS2);
                        face.push_back(indS3);
                    }
                }
                else if(s1 != 0 && s2 != 0 && s3 != 0){
                    face.push_back(indS1);
                    face.push_back(indS2);
                    face.push_back(indS3);
                }

                //** Face s4,s0,s3,s7 **//

                if( s4 != 0 ){
                    if( s0 != 0 ){
                        if( s3 != 0 ){
                            face.push_back(indS4);
                            face.push_back(indS0);
                            face.push_back(indS3);
                        }
                        else if( s7 != 0){
                            face.push_back(indS4);
                            face.push_back(indS0);
                            face.push_back(indS7);
                        }
                    }

                    if(s3 !=0 && s7 != 0){
                        face.push_back(indS4);
                        face.push_back(indS3);
                        face.push_back(indS7);
                    }
                }
                else if(s0 != 0 && s3 != 0 && s7 != 0){
                    face.push_back(indS0);
                    face.push_back(indS3);
                    face.push_back(indS7);
                }


                //** Face s4,s5,s1,s0 **//

                if( s4 != 0 ){
                    if( s5 != 0 ){
                        if( s1 != 0 ){
                            face.push_back(indS4);
                            face.push_back(indS5);
                            face.push_back(indS1);
                        }
                        else if( s0 != 0){
                            face.push_back(indS4);
                            face.push_back(indS5);
                            face.push_back(indS0);
                        }
                    }

                    if(s1 !=0 && s0 != 0){
                        face.push_back(indS4);
                        face.push_back(indS1);
                        face.push_back(indS0);
                    }
                }
                else if(s5 != 0 && s1 != 0 && s0 != 0){
                    face.push_back(indS5);
                    face.push_back(indS1);
                    face.push_back(indS0);
                }


                //** Cas particulier **//
                //**** Tronquer 1 sommet ****//

                if(s0 == 0 && s4 != 0 && s1 != 0 && s3 != 0){
                    face.push_back(indS4);
                    face.push_back(indS1);
                    face.push_back(indS3);
                }

                if(s1 == 0 && s0 != 0 && s5 != 0 && s2 != 0){
                    face.push_back(indS0);
                    face.push_back(indS5);
                    face.push_back(indS2);
                }

                if(s2 == 0 && s0 != 0 && s5 != 0 && s6 != 0){
                    face.push_back(indS0);
                    face.push_back(indS5);
                    face.push_back(indS6);
                }

                if(s3 == 0 && s4 != 0 && s2 != 0 && s7 != 0){
                    face.push_back(indS4);
                    face.push_back(indS2);
                    face.push_back(indS7);
                }

                if(s4 == 0 && s5 != 0 && s0 != 0 && s7 != 0){
                    face.push_back(indS5);
                    face.push_back(indS0);
                    face.push_back(indS7);
                }

                if(s5 == 0 && s1 != 0 && s4 != 0 && s6 != 0){
                    face.push_back(indS1);
                    face.push_back(indS4);
                    face.push_back(indS6);
                }

                if(s6 == 0 && s5 != 0 && s7 != 0 && s2 != 0){
                    face.push_back(indS5);
                    face.push_back(indS7);
                    face.push_back(indS2);
                }

                if(s7 == 0 && s4 != 0 && s3 != 0 && s6 != 0){
                    face.push_back(indS4);
                    face.push_back(indS3);
                    face.push_back(indS6);
                }

                //**** Tronquer 2~3 sommets ****//
                if(s0 == 0 ){
                    if( s1 == 0 ){
                        if(s5 != 0){
                            if(s4 != 0 && s3 != 0){
                                face.push_back(indS4);
                                face.push_back(indS5);
                                face.push_back(indS3);
                            }
                            if(s3 != 0 && s2 != 0){
                                face.push_back(indS3);
                                face.push_back(indS5);
                                face.push_back(indS2);
                            }
                        }
                        else if(s4 != 0){
                            if( s3 != 0 && s2 != 0){
                                face.push_back(indS3);
                                face.push_back(indS4);
                                face.push_back(indS2);
                            }
                            if(s2 != 0 && s5 != 0){
                                face.push_back(indS2);
                                face.push_back(indS4);
                                face.push_back(indS5);
                            }
                        }
                    }
                    if(s3 == 0 ){
                        if(s1 != 0){
                            if(s4 != 0 && s7 != 0){
                                face.push_back(indS4);
                                face.push_back(indS1);
                                face.push_back(indS7);
                            }
                            if(s7 != 0 && s2 != 0){
                                face.push_back(indS7);
                                face.push_back(indS1);
                                face.push_back(indS2);
                            }
                        }
                        else if(s4 != 0){
                            if(s7 != 0 && s2 != 0){
                                face.push_back(indS7);
                                face.push_back(indS4);
                                face.push_back(indS2);
                            }
                            if(s2 != 0 && s1 != 0){
                                face.push_back(indS2);
                                face.push_back(indS4);
                                face.push_back(indS1);
                            }
                        }
                    }
                    if(s4 == 0){
                        if(s1 != 0){
                            if(s3 != 0 && s7 != 0){
                                face.push_back(indS3);
                                face.push_back(indS1);
                                face.push_back(indS7);
                            }
                            if(s7 != 0 && s5 != 0){
                                face.push_back(indS7);
                                face.push_back(indS1);
                                face.push_back(indS5);
                            }
                        }
                        else if(s5 != 0){
                            if(s1 != 0 && s3 != 0){
                                face.push_back(indS1);
                                face.push_back(indS5);
                                face.push_back(indS3);
                            }
                            if(s3 != 0 && s7 != 0){
                                face.push_back(indS3);
                                face.push_back(indS5);
                                face.push_back(indS7);
                            }
                        }
                    }
                }

                if(s1 == 0 ){
                    if( s2 == 0 ){
                        if(s5 != 0){
                            if(s0 != 0 && s3 != 0){
                                face.push_back(indS0);
                                face.push_back(indS5);
                                face.push_back(indS3);
                            }
                            if(s3 != 0 && s6 != 0){
                                face.push_back(indS3);
                                face.push_back(indS5);
                                face.push_back(indS6);
                            }
                        }
                        else if(s6 != 0){
                            if(s5 != 0 && s0 != 0){
                                face.push_back(indS5);
                                face.push_back(indS6);
                                face.push_back(indS0);
                            }
                            if(s0 != 0 && s3 != 0){
                                face.push_back(indS0);
                                face.push_back(indS6);
                                face.push_back(indS3);
                            }
                        }
                    }
                    if(s5 == 0 ){
                        if(s4 != 0){
                            if(s6 != 0 && s2 != 0){
                                face.push_back(indS6);
                                face.push_back(indS4);
                                face.push_back(indS2);
                            }
                            if(s2 != 0 && s0 != 0){
                                face.push_back(indS2);
                                face.push_back(indS4);
                                face.push_back(indS0);
                            }
                        }
                        else if(s0 != 0){
                            if(s4 != 0 && s6 != 0){
                                face.push_back(indS4);
                                face.push_back(indS0);
                                face.push_back(indS6);
                            }
                            if(s6 != 0 && s2 != 0){
                                face.push_back(indS6);
                                face.push_back(indS0);
                                face.push_back(indS2);
                            }
                        }
                    }
                }

                if(s2 == 0 ){
                    if( s3 == 0 ){
                        if(s0 != 0){
                            if(s7 != 0 && s6 != 0){
                                face.push_back(indS7);
                                face.push_back(indS0);
                                face.push_back(indS6);
                            }
                            if(s6 != 0 && s1 != 0){
                                face.push_back(indS6);
                                face.push_back(indS0);
                                face.push_back(indS1);
                            }
                        }
                        else if(s1 != 0){
                            if(s0 != 0 && s7 != 0){
                                face.push_back(indS0);
                                face.push_back(indS1);
                                face.push_back(indS7);
                            }
                            if(s7 != 0 && s6 != 0){
                                face.push_back(indS7);
                                face.push_back(indS1);
                                face.push_back(indS6);
                            }
                        }
                    }
                    if(s6 == 0 ){
                        if(s5 != 0){
                            if(s1 != 0 && s3 != 0){
                                face.push_back(indS1);
                                face.push_back(indS5);
                                face.push_back(indS3);
                            }
                            if(s3 != 0 && s7 != 0){
                                face.push_back(indS3);
                                face.push_back(indS5);
                                face.push_back(indS7);
                            }
                        }
                        else if(s1 != 0){
                            if(s3 != 0 && s7 != 0){
                                face.push_back(indS3);
                                face.push_back(indS1);
                                face.push_back(indS7);
                            }
                            if(s7 != 0 && s5 != 0){
                                face.push_back(indS7);
                                face.push_back(indS1);
                                face.push_back(indS5);
                            }
                        }
                    }
                }

                if(s3 == 0 ){
                    if( s7 == 0 ){
                        if(s4 != 0){
                            if(s6 != 0 && s2 != 0){
                                face.push_back(indS6);
                                face.push_back(indS4);
                                face.push_back(indS2);
                            }
                            if(s2 != 0 && s0 != 0){
                                face.push_back(indS2);
                                face.push_back(indS4);
                                face.push_back(indS0);
                            }
                        }
                        else if(s0 != 0){
                            if(s4 != 0 && s6 != 0){
                                face.push_back(indS4);
                                face.push_back(indS0);
                                face.push_back(indS6);
                            }
                            if(s6 != 0 && s2 != 0){
                                face.push_back(indS6);
                                face.push_back(indS0);
                                face.push_back(indS2);
                            }
                        }
                    }
                }

                if(s4 == 0 ){
                    if( s7 == 0 ){
                        if(s0 != 0){
                            if(s5 != 0 && s6 != 0){
                                face.push_back(indS5);
                                face.push_back(indS0);
                                face.push_back(indS6);
                            }
                            if(s6 != 0 && s3 != 0){
                                face.push_back(indS6);
                                face.push_back(indS0);
                                face.push_back(indS3);
                            }
                        }
                        else if(s5 != 0){
                            if(s6 != 0 && s3 != 0){
                                face.push_back(indS6);
                                face.push_back(indS5);
                                face.push_back(indS3);
                            }
                            if(s3 != 0 && s0 != 0){
                                face.push_back(indS3);
                                face.push_back(indS5);
                                face.push_back(indS0);
                            }
                        }
                    }

                    if( s5 == 0 ){
                        if(s0 != 0){
                            if(s1 != 0 && s6 != 0){
                                face.push_back(indS1);
                                face.push_back(indS0);
                                face.push_back(indS6);
                            }
                            if(s6 != 0 && s7 != 0){
                                face.push_back(indS6);
                                face.push_back(indS0);
                                face.push_back(indS7);
                            }
                        }
                        else if(s1 != 0){
                            if(s6 != 0 && s7 != 0){
                                face.push_back(indS6);
                                face.push_back(indS1);
                                face.push_back(indS7);
                            }
                            if(s7 != 0 && s0 != 0){
                                face.push_back(indS7);
                                face.push_back(indS1);
                                face.push_back(indS0);
                            }
                        }
                    }
                }

                if(s5 == 0 ){
                    if( s6 == 0 ){
                        if(s1 != 0 ){
                            if(s4 != 0 && s7 != 0){
                                face.push_back(indS4);
                                face.push_back(indS1);
                                face.push_back(indS7);
                            }
                            if(s7 != 0 && s2 != 0){
                                face.push_back(indS7);
                                face.push_back(indS1);
                                face.push_back(indS2);
                            }
                        }
                        else if(s4 != 0){
                            if(s7 != 0 && s2 != 0){
                                face.push_back(indS7);
                                face.push_back(indS4);
                                face.push_back(indS2);
                            }
                            if(s2 != 0 && s1 != 0){
                                face.push_back(indS2);
                                face.push_back(indS4);
                                face.push_back(indS1);
                            }
                        }
                    }
                }

                if(s6 == 0 ){
                    if( s7 == 0 ){
                        if(s4 != 0){
                            if(s5 != 0 && s2 != 0){
                                face.push_back(indS5);
                                face.push_back(indS4);
                                face.push_back(indS2);
                            }
                            if(s2 != 0 && s3 != 0){
                                face.push_back(indS2);
                                face.push_back(indS4);
                                face.push_back(indS3);
                            }
                        }
                        else if(s5 != 0){
                            if(s2 != 0 && s3 != 0){
                                face.push_back(indS2);
                                face.push_back(indS5);
                                face.push_back(indS3);
                            }
                            if(s3 != 0 && s4 != 0){
                                face.push_back(indS3);
                                face.push_back(indS5);
                                face.push_back(indS4);
                            }
                        }
                    }
                }

                //**** Tronquer 4 sommets ****//

                if(s0 == 0 && s3 == 0 && s4 == 0 && s1 == 0
                        && s7 != 0 && s5 != 0 && s2 != 0){
                    face.push_back(indS7);
                    face.push_back(indS5);
                    face.push_back(indS2);
                }

                if(s1 == 0 && s0 == 0 && s2 == 0 && s5 == 0
                        && s3 != 0 && s4 != 0 && s6 != 0){
                    face.push_back(indS3);
                    face.push_back(indS4);
                    face.push_back(indS6);
                }

                if(s2 == 0 && s1 == 0 && s3 == 0 && s6 == 0
                        && s7 != 0 && s0 != 0 && s5 != 0){
                    face.push_back(indS7);
                    face.push_back(indS0);
                    face.push_back(indS5);
                }

                if(s3 == 0 && s0 == 0 && s2 == 0 && s7 == 0
                        && s4 != 0 && s1 != 0 && s6 != 0){
                    face.push_back(indS4);
                    face.push_back(indS1);
                    face.push_back(indS6);
                }

                if(s4 == 0 && s0 == 0 && s7 == 0 && s5 == 0
                        && s6 != 0 && s3 != 0 && s1 != 0){
                    face.push_back(indS6);
                    face.push_back(indS3);
                    face.push_back(indS1);
                }

                if(s5 == 0 && s4 == 0 && s3 == 0 && s6 == 0
                        && s2 != 0 && s0 != 0 && s7 != 0){
                    face.push_back(indS2);
                    face.push_back(indS0);
                    face.push_back(indS7);
                }

                if(s6 == 0 && s7 == 0 && s2 == 0 && s5 == 0
                        && s1 != 0 && s4 != 0 && s3 != 0){
                    face.push_back(indS1);
                    face.push_back(indS4);
                    face.push_back(indS3);
                }

                if(s7 == 0 && s3 == 0 && s4 == 0 && s6 == 0
                        && s5 != 0 && s0 != 0 && s2 != 0){
                    face.push_back(indS5);
                    face.push_back(indS0);
                    face.push_back(indS2);
                }
            }
        }
    }



    std::cout << "marche" << std::endl;
    std::cout << name.c_str() << std::endl;
    writeToObj(name, vertex, face);
}

void writeToObj(const std::string name, const std::vector<glm::vec3> &vertex, const std::vector<unsigned int> &face)
{
    std::cout << "marche en release" << std::endl;
    std::cout << name.c_str() << std::endl;

    std::ofstream obj;
    std::cout << "ne marche pas en release 1" << std::endl;
    obj.open(name.c_str(), std::ios::out);
    //obj.open("test.obj", std::ios::out);
    std::cout << "ne marche pas en release 2" << std::endl;

    obj << "#vertices:\n";

    for(unsigned int i = 0 ; i < vertex.size(); i++) {
        obj << "v " << std::setprecision(4) << vertex[i].x << " " << vertex[i].y << " " << vertex[i].z << "\n";
    }


    obj << "#faces:\n";

    for(unsigned int i = 0 ; i < face.size(); i += 3){
        obj << "f " << face[i] + 1 << " " << face[i+1] + 1 << " "<< face[i+2] + 1 << "\n";

    }

    obj << "\n";

    obj.close();

    std::cout << "wrote " << name << std::endl;
}

}   //end namespace ObjManager
