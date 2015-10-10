#ifndef SI_SPHERE_H
#define SI_SPHERE_H

#include "si_primitive.h"
#include "lib/sphere.h"

class SI_Sphere : public SI_Primitive, public Sphere
{
public:
    SI_Sphere(float rayonMin, float rayonMax);
    SI_Sphere(const vec3& centre, float rayonMin, float rayonMax);

    bool inOut(const glm::vec3& p, float& f) const;
    //virtual bool intersect(const Rayon& r, float &distance) const = 0;
    float distance(const glm::vec3& p) const;

protected:
    /**rayon à partir d'où la sphère implicite sera forcément affiché*/
    float rayonMin;
};

#endif // SI_SPHERE_H