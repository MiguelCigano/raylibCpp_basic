#include "ball.h"

Ball::Ball(Vector2 pos, Vector2 spd, float rad) : position(pos), speed(spd), radius(rad) {}

void Ball::Move() {
    position.x += speed.x;
    position.y += speed.y;
}

void Ball::Draw() {
    DrawCircleV(position, radius, RED);
}

void Ball::wall_collision(float screenWidth, float screenHeight) {
    if (position.x <= 0 || position.x >= screenWidth) {
            speed.x *= -1;
    }
    if (position.y <= 0) {
        speed.y *= -1;
    }
}

bool Ball::out_bounds(float screenHeight) {
    return position.y > screenHeight; // analizar
}
