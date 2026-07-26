#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Basic Graphics using raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Background
        ClearBackground(GREEN);

        // LINE
        DrawText("LINE", 50, 20, 20, BLACK);
        DrawLine(50, 40, 190, 40, BLACK);

        // RECTANGLE
        DrawText("RECTANGLE", 50, 90, 20, BLACK);
        DrawRectangleLines(125, 115, 90, 50, BLACK);

        // ARC
        DrawText("ARC", 50, 180, 20, BLACK);
        DrawRingLines((Vector2){120, 240}, 30, 30, 180, 360, 60, BLACK);

        // CIRCLE
        DrawText("CIRCLE", 50, 290, 20, BLACK);
        DrawCircleLines(120, 340, 30, BLACK);

        // ELLIPSE
        DrawText("ELLIPSE", 50, 390, 20, BLACK);
        DrawEllipseLines(120, 450, 30, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}