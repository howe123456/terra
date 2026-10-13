#include <iostream>
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"
int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Terra");
    rlImGuiSetup(true);


    ImGuiIO &io = ImGui::GetIO();
    io.FontGlobalScale = 2;


    //game main while
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            rlImGuiBegin(); 
            
            DrawText("Hello, Terra!", 10, 10, 20, RED);

            rlImGuiEnd();

    }
    rlImGuiShutdown();

    CloseWindow();

    return 0;

}