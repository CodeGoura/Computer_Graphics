#include "raylib.h"
#include <stdio.h>

#define MAX 20

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    int polyX[MAX], polyY[MAX];
    int n, i, j;
    int ymin, ymax;
    float xInt[MAX];
    int count;
    int x1, y1, x2, y2;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%d %d", &polyX[i], &polyY[i]);
    }

    InitWindow(screenWidth, screenHeight, "Scan Line Polygon Fill");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw polygon outline
        for (i = 0; i < n - 1; i++)
            DrawLine(polyX[i], polyY[i], polyX[i + 1], polyY[i + 1], WHITE);

        DrawLine(polyX[n - 1], polyY[n - 1],
                 polyX[0], polyY[0], WHITE);

        // Find ymin and ymax
        ymin = polyY[0];
        ymax = polyY[0];

        for (i = 1; i < n; i++)
        {
            if (polyY[i] < ymin)
                ymin = polyY[i];

            if (polyY[i] > ymax)
                ymax = polyY[i];
        }

        // Scan Line Fill
        for (int y = ymin; y <= ymax; y++)
        {
            count = 0;

            for (i = 0; i < n; i++)
            {
                j = (i + 1) % n;

                y1 = polyY[i];
                y2 = polyY[j];
                x1 = polyX[i];
                x2 = polyX[j];

                if ((y1 < y && y2 >= y) ||
                    (y2 < y && y1 >= y))
                {
                    xInt[count++] =
                        x1 + (float)(y - y1) *
                        (x2 - x1) / (y2 - y1);
                }
            }

            // Sort intersection points
            for (i = 0; i < count - 1; i++)
            {
                for (j = i + 1; j < count; j++)
                {
                    if (xInt[i] > xInt[j])
                    {
                        float temp = xInt[i];
                        xInt[i] = xInt[j];
                        xInt[j] = temp;
                    }
                }
            }

            // Fill between pairs of intersections
            for (i = 0; i < count - 1; i += 2)
            {
                DrawLine((int)xInt[i], y,
                         (int)xInt[i + 1], y,
                         GREEN);
            }
        }

        DrawText("White: Polygon Border", 20, 20, 20, WHITE);
        DrawText("Green: Scan Line Fill", 20, 45, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}