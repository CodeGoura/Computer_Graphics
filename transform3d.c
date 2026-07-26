#include "raylib.h"
#include <stdio.h>

#define MAX 8

// Cube vertices
int cube[MAX][3] = {
    {50, 50, 50}, {150, 50, 50},
    {150, 150, 50}, {50, 150, 50},
    {50, 50, 150}, {150, 50, 150},
    {150, 150, 150}, {50, 150, 150}
};

// Draw cube using projected 2D points
void DrawCube2D(int p[MAX][2], Color color)
{
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for (int i = 0; i < 12; i++)
    {
        DrawLine(
            p[edges[i][0]][0], p[edges[i][0]][1],
            p[edges[i][1]][0], p[edges[i][1]][1],
            color
        );
    }
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    int transformed[MAX][3];
    int parallel[MAX][2];
    int perspective[MAX][2];

    // Scaling factors
    float sx = 1.5f, sy = 1.5f, sz = 1.5f;

    // Translation factors
    int tx = 50, ty = 50, tz = 50;

    // Distance for perspective projection
    int d = 200;

    // Apply scaling and translation
    for (int i = 0; i < MAX; i++)
    {
        transformed[i][0] = (int)(cube[i][0] * sx + tx);
        transformed[i][1] = (int)(cube[i][1] * sy + ty);
        transformed[i][2] = (int)(cube[i][2] * sz + tz);
    }

    // Parallel Projection
    for (int i = 0; i < MAX; i++)
    {
        parallel[i][0] = transformed[i][0];
        parallel[i][1] = transformed[i][1];
    }

    // Perspective Projection
    for (int i = 0; i < MAX; i++)
    {
        perspective[i][0] =
            (int)(transformed[i][0] /
            (1.0f + (float)transformed[i][2] / d));

        perspective[i][1] =
            (int)(transformed[i][1] /
            (1.0f + (float)transformed[i][2] / d));
    }

    InitWindow(screenWidth, screenHeight,
               "3D Projection using raylib");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Parallel Projection (Left)
        DrawText("Parallel Projection", 60, 20, 20, GREEN);
        DrawCube2D(parallel, GREEN);

        // Shift Perspective Projection to the right
        int shifted[MAX][2];
        for (int i = 0; i < MAX; i++)
        {
            shifted[i][0] = perspective[i][0] + 350;
            shifted[i][1] = perspective[i][1];
        }

        DrawText("Perspective Projection", 420, 20, 20, YELLOW);
        DrawCube2D(shifted, YELLOW);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}