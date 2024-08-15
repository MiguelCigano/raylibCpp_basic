#include <stdio.h>
#include <raylib.h>


int main(void)
{
    const int screenWidth = 700;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Probando Raylib");

    int posicionY = screenHeight/2 - 40;
    int velocidadScroll = 8;            

    SetTargetFPS(60);         
 
    while (!WindowShouldClose())    
    {

        posicionY -= (int)(GetMouseWheelMove()*velocidadScroll);
 
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(screenWidth/2 - 40, posicionY, 80, 80, BLUE);

            DrawText("Puedes mover la caja", 10, 10, 20, BLACK);
            DrawText(TextFormat("Posicion de la caja en Y: %03i", posicionY), 10, 40, 20, MAGENTA);

        EndDrawing();  
    }

    CloseWindow();        
    
    return 0;
}