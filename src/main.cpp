#include <iostream>
#include "raylib.h"

#include "imgui.h"
int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Terra");


    //game main while
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Hello, Terra!", 10, 10, 20, RED);

        EndDrawing();

    }

    CloseWindow();

    return 0;

}