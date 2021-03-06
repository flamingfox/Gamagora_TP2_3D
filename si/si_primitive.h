#ifndef SI_PRIMITIVE_H
#define SI_PRIMITIVE_H

#include "node.h"
#include "lib/interpolation.h"

class SI_Primitive : public Node
{
public:
    SI_Primitive();
    SI_Primitive(float e, float R);

    bool inOut(const glm::vec3& p) const;
    virtual float potentiel(const glm::vec3& p) const = 0;
    //virtual bool intersect(const Rayon& r, float &distance) const = 0;
    virtual float distance(const glm::vec3& p) const =0;

    vec3 getNormal(const vec3& p, float eps = RAYON_NORMAL) const;

    void setColor(const QRgb& color);
    QRgb getColor(const vec3& p) const;

    virtual Box getBox() const = 0;

protected:
    float e;    //energie
    float R;    //rayon d'action du squelette au dela duquel la primitive n'a plus d'impact

    float falloff( float r, float R ) const;

private:
    QRgb color = DEFAULT_COLOR;
};

#endif // SI_PRIMITIVE_H
