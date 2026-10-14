#include <iostream>
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"
#include "gameMain.h"


#if PRODUCTION_BUILD == 1
    SetTraceLogLevel(LOG_NONE);
#endif
int main()
{
    Game game;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Terra");
    rlImGuiSetup(true);
    SetExitKey(KEY_NULL);
    SetTargetFPS(240);

    ImGuiIO &io = ImGui::GetIO();
    io.FontGlobalScale = 2;


    if(!game.InitGame())
    {
        return 0;
    }

    //game main while
    while (!WindowShouldClose())
    {
        BeginDrawing();
        rlImGuiBegin();

            if(!game.UpdateGame())
            {
                CloseWindow();
                return 0;
            }
        
        rlImGuiEnd();
        EndDrawing();

    }
    rlImGuiShutdown();

    CloseWindow();
    game.CloseGame();
}