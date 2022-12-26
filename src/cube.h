#ifndef CUBE_H
#define CUBE_H

#include "cubeMath.h"

class Cube{
public:
    Cube();
    ~Cube();

    void SetPosition(math::Vec3& position);
    void SetSize(math::Vec3& size);
    void SetRotation(math::Vec3 angle);

};


#endif