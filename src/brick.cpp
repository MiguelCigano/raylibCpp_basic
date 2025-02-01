#include "brick.h"

Brick::Brick(float x, float y, float width, float height) {
    rect = {x, y, width, height};
    active = true;
}

void Brick::Draw() {
    if (active != false) {
        DrawRectangleRec(rect, SKYBLUE);
    }
}