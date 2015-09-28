#include "sphere.h"

Sphere::Sphere():
    Sphere(vec3(0.f,0.f,0.f), 0)
{
}

Sphere::Sphere(const vec3 &centre, float rayon):
    centre(centre), rayon(rayon)
{

}


bool Sphere::intersect(const Rayon& r, float& minDist, float& maxDist) const
{
    vec3 op = centre - r.getOrigine();		// Solve t^2*d.d + 2*t*(o-p).d + (o-p).(o-p)-R^2 = 0
    float t,
        b = dot(r.getDirection(),op),
        det = b * b - dot(op,op) + rayon * rayon;
    if (det < 0)
        return false;
    else
        det = std::sqrt (det);

    minDist = b - det;
    if(minDist < 0)
        minDist = b + det;
    if(minDist < 0)
        return false;
    return true;
    //return (t = b - det) >= 0 ? t : ((t = b + det) >= 0 ? t : noIntersect);
}

bool Sphere::inOut(const vec3& p) const
{
    return distance2(p,centre) <= rayon*rayon;
}


