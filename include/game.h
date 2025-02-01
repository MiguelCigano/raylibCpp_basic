#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <vector>

class Game 
{
    public:
        const int screenWidth;
        const int screenHeight;
        Ball ball;
        Paddle paddle;
        std::vector<Brick> bricks;

        Game(int width, int height);
        void init_bricks();
        void update_game();
        void draw_game();
        bool game_over_game();
        bool win_game();
};

#endif