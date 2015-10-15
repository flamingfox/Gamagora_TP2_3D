﻿#include "scene.h"


Scene::Scene()
{
}


bool Scene::rendu(){
    QTime timer;
    int nbpixrouge =0;
    for(unsigned int ic = 0;  ic < cameras.size(); ic++)
    {
        Camera* c = cameras[ic];
        int _lu = c->getLu(), _lv = c->getLv();
        int pourcent2 = -1;
        QImage *img = new QImage(_lu, _lv, QImage::Format_RGB888);
        QImage eric(_lu, _lv, QImage::Format_RGB888);
        timer.start();
        #pragma omp parallel for schedule(dynamic,1)
        for(int y = 0; y < _lv ; y++){      // pour chaque ligne de l'image
            int pourcent = 100 * y / (_lv - 1);
            if(pourcent != pourcent2)            {
                pourcent2 = pourcent;
                std::cout << "\r" << ic << " Rendering: " << pourcent << "% ";  // barre de progression
            }
            for(int x = 0; x < _lu ; x++){  // pour chaque pixel de la ligne
                Rayon r(c->getOrigine(),c->vecScreen(x,y));   //rayon correspondant au pixel
                bool touche = false;


                glm::vec3 p = c->getOrigine();
                int i;
                float dist = 0;
                for(i = 0;  i < 256;    i++)
                {
                    if(node->inOut(p)){
                        touche = true;
                        break;
                    }
                    float d = node->distance(p)+0.05f;
                    dist += d;
                    if(dist > 9999) //si on va trop loin, on arrête la progression.
                        break;
                    p += r.getDirection()*(d);

                }
                if(!touche)
                    img->setPixel(x, y, default_color.rgba());
                else
                    img->setPixel(x,y, qRgb(dist*19, dist*23, dist*29));

            }
        }
        if(ic<10)        {
            std::cout << std::endl;
            int time = timer.elapsed();
            std::cout << time/1000 << "." << time%1000<< " secondes" << std::endl;
            std::cout << (100.f*nbpixrouge) / (_lu*_lv) << "%" << std::endl;
            img->save(("test000" + std::to_string(ic) + ".png").c_str());
            eric.save(("eric" + std::to_string(ic) + ".png").c_str());


            std::cout << ("test000" + std::to_string(ic) + ".png").c_str() << std::endl;
        }
        else if(ic<100)        {
            img->save(("test00" + std::to_string(ic) + ".png").c_str());
            std::cout << ("test00" + std::to_string(ic) + ".png").c_str() << std::endl;
        }
        else if(ic<1000)        {
            img->save(("test0" + std::to_string(ic) + ".png").c_str());
            std::cout << ("test0" + std::to_string(ic) + ".png").c_str() << std::endl;
        }
        else    {
            img->save(("test" + std::to_string(ic) + ".png").c_str());
            std::cout << ("test" + std::to_string(ic) + ".png").c_str() << std::endl;
        }
        delete img;
    }
    return true;
}

