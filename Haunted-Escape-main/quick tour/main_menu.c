#include "raylib.h"
#include <string.h>
#include <stdlib.h>
int main() {
    // Initialize window and OpenGL context
    InitWindow(800, 600, "Haunted Escape");

    // Load background texture (replace "background.png" with your actual texture)
    Texture2D background = LoadTexture("background.png");

    // Create font for text
    Font font = LoadFontEx("font.ttf", 36, NULL, 0);

    // Game loop
    while (!WindowShouldClose()) {
        // Update game logic here
        // (For now, we'll just handle button clicks)

        // Draw frame
        BeginDrawing();
            ClearBackground(BLACK);

            // Draw background
            DrawTextureEx(background, {0, 0}, 0, 1.0f, WHITE);

            // Draw title
            DrawTextEx(font, "HAUNTED ESCAPE", {200, 100}, 36, 2, WHITE);

            // Draw buttons
            DrawRectangle(200, 200, 200, 50, DARKGRAY);
            DrawTextEx(font, "Play", {250, 210}, 24, 2, WHITE);

            DrawRectangle(200, 300, 200, 50, DARKGRAY);
            DrawTextEx(font, "Instructions", {210, 310}, 24, 2, WHITE);

            DrawRectangle(200, 400, 200, 50, DARKGRAY);
DrawTextEx(font, "Leave Game", {220, 410}, 24, 0, WHITE);

        EndDrawing();
    }

    // De-initialize everything
    UnloadTexture(background);
    UnloadFont(font);
    CloseWindow();
    return 0;
}