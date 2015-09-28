#include "rayon.h"

Rayon::Rayon()
{

}

Rayon::Rayon(const glm::vec3& origine, const glm::vec3& direction):
        _origine(origine),  _direction(direction.normalized())
{
}

glm::vec3 Rayon::Reflect(const glm::vec3& normal) {
    const double cosI = normal.dot(_direction);
    return _direction + 2*cosI * normal;
}
