#include "Game.h"

Game::Game(int width, int height) : screenWidth(width), screenHeight(height),
    ball({ width / 2.0f, height / 2.0f }, { 4.0f, -4.0f }, 8.0f),
    paddle(width / 2.0f - 50, height - 20, 100, 10, 5.0f) {
    InitBricks();
}

void Game::InitBricks() {
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

void Game::Update() {
    ball.Move();
    ball.CheckWallCollision(screenWidth, screenHeight);

    if (CheckCollisionCircleRec(ball.position, ball.radius, paddle.rect)) {
        ball.speed.y *= -1;
        ball.position.y = paddle.rect.y - ball.radius;
    }

    for (auto& brick : bricks) {
        if (brick.active && CheckCollisionCircleRec(ball.position, ball.radius, brick.rect)) {
            brick.active = false;
            ball.speed.y *= -1;
            break;
        }
    }

    paddle.Move(screenWidth);
}

void Game::Draw() {
    ball.Draw();
    paddle.Draw();
    for (auto& brick : bricks) {
        brick.Draw();
    }
}

bool Game::IsGameOver() {
    return ball.IsOutOfBounds(screenHeight);
}

bool Game::IsWin() {
    for (auto& brick : bricks) {
        if (brick.active) return false;
    }
    return true;
}
