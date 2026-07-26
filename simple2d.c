#include "raylib.h"

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Basic Graphics Objects");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        //==================== HOUSE ====================
        DrawText("HOUSE", 60, 20, 20, WHITE);

        DrawRectangleLines(60, 80, 90, 120, SKYBLUE);
        DrawRectangleLines(95, 140, 25, 60, SKYBLUE);

        DrawLine(60, 80, 105, 20, SKYBLUE);
        DrawLine(105, 20, 150, 80, SKYBLUE);

        DrawCircleLines(105, 60, 10, YELLOW);

        //==================== CAR ====================
        DrawText("CAR", 330, 20, 20, WHITE);

        DrawLine(350,100,442,100,RED);
        DrawEllipseLines(442,105,10,5,RED);

        DrawLine(350,100,320,150,RED);
        DrawLine(452,105,480,150,RED);

        DrawLine(300,150,520,150,RED);
        DrawLine(300,150,300,200,RED);
        DrawLine(520,150,520,200,RED);

        DrawLine(300,200,310,200,RED);
        DrawLine(520,200,510,200,RED);
        DrawLine(450,200,350,200,RED);

        DrawCircleLines(330,200,17,WHITE);
        DrawCircleLines(490,200,17,WHITE);

        //==================== FISH ====================
        DrawText("FISH", 650, 20, 20, WHITE);

        DrawEllipseLines(760,200,90,30,GREEN);

        DrawCircle(690,193,3,WHITE);       // Eye

        DrawLine(670,200,690,200,GREEN);   // Mouth

        DrawLine(847,185,880,170,GREEN);
        DrawLine(847,215,880,227,GREEN);
        DrawLine(880,170,880,227,GREEN);

        DrawLine(847,200,880,200,GREEN);
        DrawLine(847,192,880,187,GREEN);
        DrawLine(847,207,880,213,GREEN);

        DrawLine(740,190,780,150,GREEN);
        DrawLine(770,190,780,150,GREEN);

        //==================== MAN ====================
        DrawText("MAN", 100, 380, 20, WHITE);

        DrawCircleLines(150,450,35,YELLOW);

        DrawLine(150,485,150,600,YELLOW);

        DrawLine(150,500,120,530,YELLOW);
        DrawLine(150,500,180,530,YELLOW);

        DrawLine(150,600,120,630,YELLOW);
        DrawLine(150,600,180,630,YELLOW);

        DrawText("HI, THIS IS COMPUTER GRAPHICS",
                 250, 620, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}