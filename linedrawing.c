#include "raylib.h"
#include <stdio.h>

int main(void)
{
    int x1, y1, x2, y2;
    int dx, dy, p;

    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    InitWindow(800, 600, "Bresenham Line Drawing Algorithm");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        dx = x2 - x1;
        dy = y2 - y1;
        p = 2 * dy - dx;

        int x = x1;
        int y = y1;

        while (x <= x2)
        {
            DrawPixel(x, y, WHITE);

            x++;

            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                y++;
                p = p + 2 * (dy - dx);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}