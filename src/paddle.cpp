#include "paddle.h"

Paddle::Paddle(float x, float y, float width, float height, float spd) {
    rect = {x, y, width, height};
    speed = spd;
}

void Paddle::Move (float screenWidth) {
    if (IsKeyDown(KEY_LEFT) && rect.x > 0) {
        rect.x -=speed;
    }
    if (IsKeyDown(KEY_RIGHT) && rect.x + rect.width < screenWidth) {
        rect.x +=speed;
    }
}

void Paddle::Draw() {
    DrawRectangleRec(rect, SKYBLUE);
}



