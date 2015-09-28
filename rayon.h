#ifndef RAYON_H
#define RAYON_H
#include <glm/vec3.hpp>

class Rayon
{
public:
    Rayon();

    /**
     * @brief position d'origine du rayon.
     */
   glm::vec3 _origine;
    /**
     * @brief direction du rayon.
     */
    glm::vec3 _direction;

    inline glm::vec3 getOrigine()const{return _origine;}
    inline glm::vec3 getDirection()const{return _direction;}
};

#endif // RAYON_H
