#include "raylib.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib - Load and Draw Image");

    // Load image and convert to texture
    Texture2D texture = LoadTexture("start.jpg"); // Replace with your image file name

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update logic goes here (if needed)

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Here is the loaded image:", 10, 10, 20, DARKGRAY);
        DrawTexture(texture, 100, 100, WHITE); // Draw the texture at position (100, 100)

        EndDrawing();
    }

    // De-initialization
    UnloadTexture(texture); // Unload texture from GPU memory
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
