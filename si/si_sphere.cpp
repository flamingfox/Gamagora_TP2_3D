#include "si_sphere.h"


SI_Sphere::SI_Sphere(float rayonMin, float rayonMax):
        Sphere(vec3(0,0,0), rayonMax), rayonMin(rayonMin)
{

}

SI_Sphere::SI_Sphere(const vec3& centre, float rayonMin, float rayonMax):
        Sphere(centre, rayonMax),   rayonMin(rayonMin)
{

}

float SI_Sphere::potentiel(const vec3 &p) const
{
    float dist2 = distance2(p,centre);

    if(dist2 >= rayon*rayon)
        return 0.f;
    else if(dist2 <= rayonMin*rayonMin)
        return 1.f;

    float f = interp::interp_linear1D(dist2, 1.f, 0.f, rayonMin*rayonMin, rayon*rayon);
    return f*f;
}

float SI_Sphere::distance(const vec3 &p) const
{
    float dst2 = glm::distance2(p, centre) - rayonMin*rayonMin;

    if(dst2 > 0)
        return dst2;
    else
        return 0;
}
