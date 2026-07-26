#include "raylib.h"

void DrawMan(int x)
{
    // Head
    DrawCircle(x, 50, 30, GREEN);
    DrawCircleLines(x, 50, 30, WHITE);

    // Body
    DrawLine(x, 80, x, 200, MAGENTA);

    // Left Arm
    DrawLine(x, 110, x - 30, 140, MAGENTA);

    // Right Arm
    DrawLine(x, 110, x + 30, 140, MAGENTA);

    // Left Leg
    DrawLine(x, 200, x - 30, 230, MAGENTA);

    // Right Leg
    DrawLine(x, 200, x + 30, 230, MAGENTA);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Moving Man Animation");
    SetTargetFPS(60);

    int x = 50;
    int direction = 1;     // 1 = right, -1 = left

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Moving Man Animation", 20, 20, 20, WHITE);

        DrawMan(x);

        EndDrawing();

        // Move the man
        x += direction * 3;

        // Change direction at screen edges
        if (x >= screenWidth - 40)
            direction = -1;

        if (x <= 40)
            direction = 1;
    }

    CloseWindow();
    return 0;
}