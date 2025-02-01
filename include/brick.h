#ifndef BRICK_H
#define BRICK_H

#include "raylib.h"

class Brick 
{
    public:
        Rectangle rect;
        bool active;

        // constructor
        Brick(float x, float y, float width, float height);
        void Draw();
};

#endif