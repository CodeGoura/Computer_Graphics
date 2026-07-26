#include "raylib.h"
#include <stdio.h>

#define TOP 1
#define BOTTOM 2
#define RIGHT 4
#define LEFT 8

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

int ComputeCode(double x, double y)
{
    int code = 0;

    if (y > ymax)
        code |= TOP;
    else if (y < ymin)
        code |= BOTTOM;

    if (x > xmax)
        code |= RIGHT;
    else if (x < xmin)
        code |= LEFT;

    return code;
}

int CohenSutherland(double *x1, double *y1, double *x2, double *y2)
{
    int code1 = ComputeCode(*x1, *y1);
    int code2 = ComputeCode(*x2, *y2);
    int accept = 0;

    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int codeOut;
            double x, y;

            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            if (codeOut & TOP)
            {
                x = *x1 + (*x2 - *x1) * (ymax - *y1) / (*y2 - *y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {
                x = *x1 + (*x2 - *x1) * (ymin - *y1) / (*y2 - *y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                y = *y1 + (*y2 - *y1) * (xmax - *x1) / (*x2 - *x1);
                x = xmax;
            }
            else
            {
                y = *y1 + (*y2 - *y1) * (xmin - *x1) / (*x2 - *x1);
                x = xmin;
            }

            if (codeOut == code1)
            {
                *x1 = x;
                *y1 = y;
                code1 = ComputeCode(*x1, *y1);
            }
            else
            {
                *x2 = x;
                *y2 = y;
                code2 = ComputeCode(*x2, *y2);
            }
        }
    }

    return accept;
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    double x1, y1, x2, y2;
    double cx1, cy1, cx2, cy2;

    printf("Enter line endpoints (x1 y1 x2 y2): ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    cx1 = x1;
    cy1 = y1;
    cx2 = x2;
    cy2 = y2;

    int accept = CohenSutherland(&cx1, &cy1, &cx2, &cy2);

    InitWindow(screenWidth, screenHeight, "Cohen-Sutherland Line Clipping");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Clipping window
        DrawRectangleLines(xmin, ymin, xmax - xmin, ymax - ymin, GREEN);

        // Original line (Red)
        DrawLine((int)x1, (int)y1, (int)x2, (int)y2, RED);

        // Clipped line (White)
        if (accept)
        {
            DrawLine((int)cx1, (int)cy1, (int)cx2, (int)cy2, WHITE);
        }

        DrawText("Red: Original Line", 20, 20, 20, RED);
        DrawText("White: Clipped Line", 20, 45, 20, WHITE);
        DrawText("Green: Clipping Window", 20, 70, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}