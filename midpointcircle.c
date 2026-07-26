#include "raylib.h"
#include <stdio.h>
void DrawCirclePoints(int xc, int yc, int x, int y, Color color)
{
    DrawPixel(xc + x, yc + y, color);
    DrawPixel(xc - x, yc + y, color);
    DrawPixel(xc + x, yc - y, color);
    DrawPixel(xc - x, yc - y, color);

    DrawPixel(xc + y, yc + x, color);
    DrawPixel(xc - y, yc + x, color);
    DrawPixel(xc + y, yc - x, color);
    DrawPixel(xc - y, yc - x, color);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Midpoint Circle Algorithm - raylib");

    int xc, yc, r;

    printf("Enter center of circle (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        int x = 0;
        int y = r;
        int p = 1 - r;

        DrawCirclePoints(xc, yc, x, y, WHITE);

        while (x < y)
        {
            x++;

            if (p < 0)
            {
                p = p + 2 * x + 1;
            }
            else
            {
                y--;
                p = p + 2 * x + 1 - 2 * y;
            }

            DrawCirclePoints(xc, yc, x, y, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}