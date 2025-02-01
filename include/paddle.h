#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

class Paddle
{
    public:
        Rectangle rect;
        float speed;

        // constructor
        Paddle (float x, float y, float width, float height, float spd);
        void Move(float screenWidth);
        void Draw();
};

#endif