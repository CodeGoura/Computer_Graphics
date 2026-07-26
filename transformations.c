#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define MAX 10
// #define PI 3.14159265

void DrawObject(int x[], int y[], int n, Color color)
{
    for (int i = 0; i < n - 1; i++)
    {
        DrawLine(x[i], y[i], x[i + 1], y[i + 1], color);
    }

    DrawLine(x[n - 1], y[n - 1], x[0], y[0], color);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    int x[MAX], y[MAX];
    int originalX[MAX], originalY[MAX];

    int n;
    int tx, ty;
    float sx, sy, angle;
    int choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);

        originalX[i] = x[i];
        originalY[i] = y[i];
    }

    printf("\n1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter translation factors (tx ty): ");
            scanf("%d %d", &tx, &ty);

            for (int i = 0; i < n; i++)
            {
                x[i] += tx;
                y[i] += ty;
            }
            break;

        case 2:
            printf("Enter scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);

            for (int i = 0; i < n; i++)
            {
                x[i] = (int)(x[i] * sx);
                y[i] = (int)(y[i] * sy);
            }
            break;

        case 3:
            printf("Enter rotation angle (degrees): ");
            scanf("%f", &angle);

            angle = angle * PI / 180.0;

            for (int i = 0; i < n; i++)
            {
                int xNew = (int)(x[i] * cos(angle) - y[i] * sin(angle));
                int yNew = (int)(x[i] * sin(angle) + y[i] * cos(angle));

                x[i] = xNew;
                y[i] = yNew;
            }
            break;

        default:
            printf("Invalid Choice!\n");
            return 0;
    }

    InitWindow(screenWidth, screenHeight, "2D Transformations - raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Original Object
        DrawObject(originalX, originalY, n, RED);
        DrawText("Original Object", 20, 20, 20, RED);

        // Transformed Object
        DrawObject(x, y, n, GREEN);
        DrawText("Transformed Object", 20, 50, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}