#include "raylib.h"

#define GROUND_Y 500

// Draw walking man
void DrawWalkingMan(int x, int legOffset, int armOffset)
{
    // Head
    DrawCircle(x, 200, 20, YELLOW);
    DrawCircleLines(x, 200, 20, WHITE);

    // Body
    DrawLine(x, 220, x, 320, WHITE);

    // Arms
    DrawLine(x, 250, x - 30, 250 + armOffset, WHITE);
    DrawLine(x, 250, x + 30, 250 - armOffset, WHITE);

    // Legs
    DrawLine(x, 320, x - 20, 380 + legOffset, WHITE);
    DrawLine(x, 320, x + 20, 380 - legOffset, WHITE);
}

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Man Walking Animation");
    SetTargetFPS(60);

    int x = 50;
    int direction = 1;

    int legOffset = 0;
    int armOffset = 0;
    int swing = 1;

    while (!WindowShouldClose())
    {
        // Move man
        x += direction * 2;

        // Reverse direction at edges
        if (x > screenWidth - 50)
            direction = -1;

        if (x < 50)
            direction = 1;

        // Walking animation
        legOffset += swing;
        armOffset += swing;

        if (legOffset >= 15 || legOffset <= -15)
            swing = -swing;

        BeginDrawing();
        ClearBackground(BLACK);

        // Ground
        DrawLine(0, GROUND_Y, screenWidth, GROUND_Y, BROWN);

        // Draw man
        DrawWalkingMan(x, legOffset, armOffset);

        DrawText("MAN WALKING ANIMATION", 20, 20, 25, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}