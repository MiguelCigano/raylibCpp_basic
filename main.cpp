/*
BreakerBrock/
├── src/
│   ├── main.cpp        // Punto de entrada principal
│   ├── Game.cpp        // Implementación de la clase Game
│   ├── Ball.cpp        // Implementación de la clase Ball
│   ├── Paddle.cpp      // Implementación de la clase Paddle
│   └── Brick.cpp       // Implementación de la clase Brick
├── include/
│   ├── Game.h          // Declaración de la clase Game
│   ├── Ball.h          // Declaración de la clase Ball
│   ├── Paddle.h        // Declaración de la clase Paddle
│   └── Brick.h         // Declaración de la clase Brick
└── Makefile            // Script para compilar el proyecto
*/

#include "raylib.h"
#include "game.h"
#include <vector>

Game::Game(int width, int height) : screenWidth(width), screenHeight(height),
    ball({ width / 2.0f, height / 2.0f }, { 4.0f, -4.0f }, 8.0f),
    paddle(width / 2.0f - 50, height - 20, 100, 10, 5.0f) {
        init_bricks();
}

void Game::init_bricks() {
    const int rows    =  6;
    const int columns = 10;
    const float brick_width  = screenWidth / columns;
    const float brick_height = 20;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            bricks.emplace_back(
                j * brick_width, 
                i * brick_height, 
                brick_width - 2, 
                brick_height - 2 );
        }
    }
}

void Game::update_game() {
    ball.Move();
    ball.wall_collision(screenWidth, screenHeight);
    
    // Paddle collision
    if (CheckCollisionCircleRec(ball.position, ball.radius, paddle.rect)) {
        ball.speed.y *= -1;
        ball.position.y = paddle.rect.y - ball.radius; // adjust position to avoid sticking
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

void Game::draw_game() {
    ball.Draw();
    paddle.Draw();
    for (auto& brick : bricks) {
        brick.Draw();
    }
}

bool Game::game_over_game() {
    return ball.out_bounds(screenHeight);
}

bool Game::win_game() {
    for (auto& brick : bricks) {
        if (brick.active) {
            return false;
        }
    }
    return true;
}

int main() 
{
    const int screenWidth  = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "BBplay");
    Game game(screenWidth, screenHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        if (game.game_over_game()) {
            DrawText("Game Over!!!", (screenWidth / 2) - 100, screenHeight / 2, 20, RED );
        }
        else if (game.win_game()) {
            DrawText("You Win!!", (screenWidth / 2) - 100, screenHeight / 2, 20, GREEN );
        }
        else {
            game.update_game();
            game.draw_game();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}