#include "raylib.h"
#include <stdio.h>

#define MAX 20

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

typedef struct
{
    float x, y;
} Point;

Point poly[MAX], clip[MAX];
int n;

int inside(Point p, int edge)
{
    switch (edge)
    {
        case 0: return p.x >= xmin;   // Left
        case 1: return p.x <= xmax;   // Right
        case 2: return p.y >= ymin;   // Bottom
        case 3: return p.y <= ymax;   // Top
    }
    return 0;
}

Point intersect(Point p1, Point p2, int edge)
{
    Point p;
    float m = 0;

    if (p1.x != p2.x)
        m = (p2.y - p1.y) / (p2.x - p1.x);

    switch (edge)
    {
        case 0:     // Left
            p.x = xmin;
            p.y = p1.y + m * (xmin - p1.x);
            break;

        case 1:     // Right
            p.x = xmax;
            p.y = p1.y + m * (xmax - p1.x);
            break;

        case 2:     // Bottom
            p.y = ymin;
            if (p1.x != p2.x)
                p.x = p1.x + (ymin - p1.y) / m;
            else
                p.x = p1.x;
            break;

        case 3:     // Top
            p.y = ymax;
            if (p1.x != p2.x)
                p.x = p1.x + (ymax - p1.y) / m;
            else
                p.x = p1.x;
            break;
    }

    return p;
}

int clipPolygon(Point in[], int inCount, int edge, Point out[])
{
    Point s, p;
    int outCount = 0;

    s = in[inCount - 1];

    for (int i = 0; i < inCount; i++)
    {
        p = in[i];

        if (inside(p, edge))
        {
            if (!inside(s, edge))
                out[outCount++] = intersect(s, p, edge);

            out[outCount++] = p;
        }
        else if (inside(s, edge))
        {
            out[outCount++] = intersect(s, p, edge);
        }

        s = p;
    }

    return outCount;
}

void DrawPolygonLinesCustom(Point p[], int count, Color color)
{
    for (int i = 0; i < count - 1; i++)
    {
        DrawLine((int)p[i].x, (int)p[i].y,
                 (int)p[i + 1].x, (int)p[i + 1].y, color);
    }

    DrawLine((int)p[count - 1].x, (int)p[count - 1].y,
             (int)p[0].x, (int)p[0].y, color);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%f %f", &poly[i].x, &poly[i].y);
    }

    Point original[MAX];
    int originalCount = n;

    for (int i = 0; i < n; i++)
        original[i] = poly[i];

    n = clipPolygon(poly, n, 0, clip);
    n = clipPolygon(clip, n, 1, poly);
    n = clipPolygon(poly, n, 2, clip);
    n = clipPolygon(clip, n, 3, poly);

    InitWindow(screenWidth, screenHeight,
               "Sutherland-Hodgman Polygon Clipping");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Clipping Window
        DrawRectangleLines(xmin, ymin,
                           xmax - xmin,
                           ymax - ymin,
                           GREEN);

        // Original Polygon
        DrawPolygonLinesCustom(original, originalCount, RED);

        // Clipped Polygon
        if (n > 0)
            DrawPolygonLinesCustom(poly, n, WHITE);

        DrawText("Green : Clipping Window", 20, 20, 20, GREEN);
        DrawText("Red   : Original Polygon", 20, 45, 20, RED);
        DrawText("White : Clipped Polygon", 20, 70, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}