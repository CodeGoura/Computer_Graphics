#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int radius = 50;

    InitWindow(screenWidth, screenHeight, "Circle Animation");
    SetTargetFPS(60);

    int x = 50;
    int y = 50;

    int stage = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(x, y, radius, BLUE);
        DrawCircleLines(x, y, radius, SKYBLUE);

        DrawText("Circle Animation", 20, 20, 20, WHITE);

        EndDrawing();

        switch(stage)
        {
            // Left -> Right
            case 0:
                x += 3;
                if (x >= screenWidth - radius)
                    stage = 1;
                break;

            // Right -> Left
            case 1:
                x -= 3;
                if (x <= radius)
                    stage = 2;
                break;

            // Top -> Bottom
            case 2:
                y += 3;
                if (y >= screenHeight - radius)
                    stage = 3;
                break;

            // Bottom -> Top
            case 3:
                y -= 3;
                if (y <= radius)
                {
                    x = radius;
                    y = radius;
                    stage = 4;
                }
                break;

            // Diagonal Down-Right
            case 4:
                x += 3;
                y += 3;
                if (x >= screenWidth - radius ||
                    y >= screenHeight - radius)
                    stage = 5;
                break;

            // Diagonal Up-Left
            case 5:
                x -= 3;
                y -= 3;
                if (x <= radius || y <= radius)
                    stage = 0;
                break;
        }
    }

    CloseWindow();
    return 0;
}