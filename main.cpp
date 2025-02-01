#include <stdio.h>
#include <iostream>
#include "raylib.h"

// int main() {
//     // Inicializar ventana
//     const int screenWidth = 800;
//     const int screenHeight = 600;
//     InitWindow(screenWidth, screenHeight, "Barra de Volumen - raylib");

//     // Variables de control
//     int volume = 50; // Rango de 0 a 100
//     const int volumeBarWidth = 400;
//     const int volumeBarHeight = 20;
//     const int volumeBarX = (screenWidth - volumeBarWidth) / 2;
//     const int volumeBarY = screenHeight / 2;

//     bool dragging = false;

//     SetTargetFPS(60);

//     while (!WindowShouldClose()) {
//         // Detectar clic y arrastre
//         Vector2 mousePos = GetMousePosition();
//         if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
//             // Revisar si el clic fue dentro de la barra
//             if (CheckCollisionPointRec(mousePos, (Rectangle){ volumeBarX, volumeBarY, volumeBarWidth, volumeBarHeight })) {
//                 dragging = true;
//             }
//         }
//         if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
//             dragging = false;
//         }

//         // Ajustar volumen si se está arrastrando
//         if (dragging) {
//             volume = ((mousePos.x - volumeBarX) * 100) / volumeBarWidth;
//             if (volume < 0) volume = 0;
//             if (volume > 100) volume = 100;
//         }

//         // Dibujar en pantalla
//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         DrawText("Drag to set volumen", 10, 10, 20, PINK);

//         // Dibujar barra de volumen vacía
//         DrawRectangle(volumeBarX, volumeBarY, volumeBarWidth, volumeBarHeight, LIGHTGRAY);
//         // Dibujar nivel de volumen
//         DrawRectangle(volumeBarX, volumeBarY, volume * (volumeBarWidth / 100), volumeBarHeight, PINK);
//         // Dibujar borde de la barra
//         DrawRectangleLines(volumeBarX, volumeBarY, volumeBarWidth, volumeBarHeight, BLACK);

//         // Mostrar porcentaje de volumen
//         DrawText(TextFormat("Volumen: %d%%", volume), volumeBarX + volumeBarWidth / 2 - 50, volumeBarY - 30, 20, BLACK);

//         EndDrawing();
//     }

//     CloseWindow(); // Cerrar ventana
//     return 0;
// }



#include "raylib.h"

// Clase para la barra de volumen
class BarraDeVolumen {
    private:
        int x, y;               // Posición de la barra
        int width, height;      // Dimensiones de la barra
        int volumen;            // Nivel de volumen (0-100)
        bool arrastrando;       // Estado de arrastre

    public:
        // Constructor
        BarraDeVolumen(int posX, int posY, int ancho, int alto, int volumenInicial)
            : x(posX), y(posY), width(ancho), height(alto), volumen(volumenInicial), arrastrando(false) {}

        // Método para dibujar la barra
        void Dibujar() const {
            // Dibujar barra vacía
            DrawRectangle(x, y, width, height, VIOLET);
            // Dibujar nivel actual de volumen
            DrawRectangle(x, y, volumen * width / 100, height, PINK);
            // Dibujar borde
            DrawRectangleLines(x, y, width, height, BLACK);
            // Dibujar texto del porcentaje de volumen
            DrawText(TextFormat("%d%%", volumen), x + width / 2 - 20, y - 30, 20, BLACK);
        }

        // Método para actualizar el estado de la barra según la interacción del mouse
        void Actualizar() {
            Vector2 mousePos = GetMousePosition();

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(mousePos, { (float)x, (float)y, (float)width, (float)height })) {
                    arrastrando = true;
                }
            }
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                arrastrando = false;
            }

            if (arrastrando) {
                volumen = ((mousePos.x - x) * 100) / width;
                if (volumen < 0) volumen = 0;
                if (volumen > 100) volumen = 100;
            }
        }

        // Obtener el volumen actual
        int GetVolumen() const {
            return volumen;
        }
};

int main() {
    // Inicializar ventana
    const int screenWidth = 500;
    const int screenHeight = 300;
    InitWindow(screenWidth, screenHeight, "Barra de Volumen con Clases - raylib");

    // Crear una instancia de la clase BarraDeVolumen
    BarraDeVolumen barra((screenWidth - 400) / 2, screenHeight / 2, 400, 20, 50);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Actualizar la barra
        barra.Actualizar();

        // Dibujar todo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Drag to set", 100, 100, 20, DARKGRAY);
        barra.Dibujar(); // Usar el método de la clase para dibujar la barra

        EndDrawing();
    }

    CloseWindow();
    return 0;
}