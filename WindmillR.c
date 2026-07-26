#include "raylib.h"
#include <math.h>

// #define PI 3.14159265f

// Draw one blade
void DrawBlade(Vector2 center, float angle)
{
    float r1 = 100.0f;
    float r2 = 70.0f;
    float width = 20.0f;

    float rad = angle * PI / 180.0f;

    Vector2 p1 = {
        center.x + cosf(rad) * r1,
        center.y + sinf(rad) * r1
    };

    Vector2 p2 = {
        center.x + cosf(rad + 0.2f) * r2,
        center.y + sinf(rad + 0.2f) * r2
    };

    Vector2 p3 = {
        center.x + cosf(rad - 0.2f) * r2,
        center.y + sinf(rad - 0.2f) * r2
    };

    DrawTriangle(p1, p2, p3, SKYBLUE);
    DrawTriangleLines(p1, p2, p3, WHITE);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Windmill Rotation");
    SetTargetFPS(60);

    Vector2 center = {400, 200};
    float angle = 0.0f;

    while (!WindowShouldClose())
    {
        angle += 2.0f;
        if (angle >= 360.0f)
            angle = 0.0f;

        BeginDrawing();
        ClearBackground(BLACK);

        // Windmill Tower
        DrawLine(380, 200, 350, 500, DARKGRAY);
        DrawLine(420, 200, 450, 500, DARKGRAY);
        DrawLine(340, 500, 460, 500, DARKGRAY);

        // Hub
        DrawCircleV(center, 8, RED);

        // Three rotating blades
        DrawBlade(center, angle);
        DrawBlade(center, angle + 120);
        DrawBlade(center, angle + 240);

        DrawText("Windmill Rotation", 20, 20, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}