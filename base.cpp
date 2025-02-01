// Breaker Brock - A Brick Breaker Game using Raylib and C++
#include "raylib.h"
#include <vector>

// Ball class
class Ball {
public:
    Vector2 position;
    Vector2 speed;
    float radius;
    
    Ball(Vector2 pos, Vector2 spd, float rad) : position(pos), speed(spd), radius(rad) {}

    void Move() {
        position.x += speed.x;
        position.y += speed.y;
    }

    void Draw() {
        DrawCircleV(position, radius, RED);
    }

    void CheckWallCollision(float screenWidth, float screenHeight) {
        if (position.x <= 0 || position.x >= screenWidth) speed.x *= -1;
        if (position.y <= 0) speed.y *= -1;
    }

    bool IsOutOfBounds(float screenHeight) {
        return position.y > screenHeight;
    }
};

// Brick class
class Brick {
public:
    Rectangle rect;
    bool active;

    Brick(float x, float y, float width, float height)
        : rect{ x, y, width, height }, active(true) {}

    void Draw() {
        if (active) {
            DrawRectangleRec(rect, BLUE);
        }
    }
};

// Paddle class
class Paddle {
public:
    Rectangle rect;
    float speed;

    Paddle(float x, float y, float width, float height, float spd)
        : rect{ x, y, width, height }, speed(spd) {}

    void Move(float screenWidth) {
        if (IsKeyDown(KEY_LEFT) && rect.x > 0) rect.x -= speed;
        if (IsKeyDown(KEY_RIGHT) && rect.x + rect.width < screenWidth) rect.x += speed;
    }

    void Draw() {
        DrawRectangleRec(rect, GREEN);
    }
};

// Game class
class Game {
public:
    const int screenWidth;
    const int screenHeight;
    Ball ball;
    Paddle paddle;
    std::vector<Brick> bricks;

    Game(int width, int height)
        : screenWidth(width), screenHeight(height),
          ball({ width / 2.0f, height / 2.0f }, { 4.0f, -4.0f }, 8.0f),
          paddle(width / 2.0f - 50, height - 20, 100, 10, 5.0f) {
        InitBricks();
    }

    void InitBricks() {
        const int rows = 5;
        const int cols = 10;
        const float brickWidth = screenWidth / cols;
        const float brickHeight = 20;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bricks.emplace_back(j * brickWidth, i * brickHeight, brickWidth - 2, brickHeight - 2);
            }
        }
    }

    void Update() {
        ball.Move();
        ball.CheckWallCollision(screenWidth, screenHeight);

        // Paddle collision
        if (CheckCollisionCircleRec(ball.position, ball.radius, paddle.rect)) {
            ball.speed.y *= -1;
            ball.position.y = paddle.rect.y - ball.radius; // Adjust position to avoid sticking
        }

        // Brick collisions
        for (auto& brick : bricks) {
            if (brick.active && CheckCollisionCircleRec(ball.position, ball.radius, brick.rect)) {
                brick.active = false;
                ball.speed.y *= -1;
                break;
            }
        }

        // Paddle movement
        paddle.Move(screenWidth);
    }

    void Draw() {
        ball.Draw();
        paddle.Draw();

        for (auto& brick : bricks) {
            brick.Draw();
        }
    }

    bool IsGameOver() {
        return ball.IsOutOfBounds(screenHeight);
    }

    bool IsWin() {
        for (auto& brick : bricks) {
            if (brick.active) return false;
        }
        return true;
    }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Breaker Brock");

    Game game(screenWidth, screenHeight);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if (game.IsGameOver()) {
            DrawText("Game Over!", screenWidth / 2 - 100, screenHeight / 2, 20, RED);
        } else if (game.IsWin()) {
            DrawText("You Win!", screenWidth / 2 - 100, screenHeight / 2, 20, GREEN);
        } else {
            game.Update();
            game.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
