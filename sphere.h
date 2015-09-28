#ifndef SPHERE_H
#define SPHERE_H

#include <glm/vec3.hpp>
#include <glm/gtx/norm.hpp> //ajouté
#include "rendu/rayon.h"

using namespace glm;

class Sphere
{
public:
    Sphere();
    Sphere(const vec3& centre, float rayon);

    bool intersect(const Rayon& r, float& minDist, float& maxDist) const;
    bool inOut(const vec3& p) const;

    private:

    vec3 centre;
    float rayon;
};

#endif // SPHERE_H
