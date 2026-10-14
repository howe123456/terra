#pragma once
#include <raylib.h>
struct g_game_pos 
{
    float positionX = 100;
    float positionY = 100;
};

class Game{
public:
    float m_deltaTime = 0; 
    g_game_pos m_pos;

    bool InitGame();
    bool UpdateGame();
    void CloseGame(); 
};