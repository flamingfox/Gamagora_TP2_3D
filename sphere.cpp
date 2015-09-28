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
    vec3 diff = centre-r.getOrigine();

    vec3 l = diff*r.getDirection();
    float h2 = diff*diff-l*l;
    if(h2> rayon*rayon)
        return false;

    float a2 = rayon*rayon-h2;   //pythagore: a2+h2 = rayon²    pa = point sur la sphère,  a = distance entre le point h qui forme un angle à 90° entre le rayon à h->centre

    float diff2 = length2(diff);
    float b2 = diff2 - h2;      //pythagore: h2+b2 = diff2

    minDist = b2-a2;
    maxDist = b2+a2;

    /*vec3 op = centre - r.getOrigine();		// Solve t^2*d.d + 2*t*(o-p).d + (o-p).(o-p)-R^2 = 0
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
    return true;*/
    //return (t = b - det) >= 0 ? t : ((t = b + det) >= 0 ? t : noIntersect);
}

bool Sphere::inOut(const vec3& p) const
{
    return distance2(p,centre) <= rayon*rayon;
}


