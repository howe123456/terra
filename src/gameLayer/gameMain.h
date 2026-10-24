#pragma once
#include <raylib.h>
#include "AssetManager.h"
#include "gameMap.h"

struct g_gamePos 

{
    float positionX = 100;
    float positionY = 100;
};

struct g_gameData
{
    g_gameMap gameMap;
    Camera2D m_camera;
};

class Game{
public:
    Block m_block;
    AssetManager m_assetManager;
    float m_deltaTime = 0; 
    g_gamePos m_pos;
    g_gameData m_data;
    bool InitGame();
    bool UpdateGame();
    void CloseGame(); 
};