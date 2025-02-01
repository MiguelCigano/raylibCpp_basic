#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball
{
    public:
        Vector2 position;
        Vector2 speed;
        float radius;

        // constructor
        Ball(Vector2 pos, Vector2 spd, float rad);
        void Move();
        void Draw();
        void wall_collision(float screen_width, float screen_height);
        bool out_bounds(float screenHight);
    
    private:
        // TODO
};

#endif