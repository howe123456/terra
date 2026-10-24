#include "gameMain.h"


bool Game::InitGame()
{
    m_assetManager.loadALL();
    m_data.gameMap.create(30,10);

    m_data.gameMap.getBlockUnsafe(0,0).type = m_block.dirt;
    m_data.gameMap.getBlockUnsafe(1,1).type = m_block.dirt;
    m_data.gameMap.getBlockUnsafe(2,2).type = m_block.dirt;
    m_data.gameMap.getBlockUnsafe(3,3).type = m_block.dirt;
    m_data.gameMap.getBlockUnsafe(4,4).type = m_block.dirt;

    m_data.m_camera.target = {0,0};
    m_data.m_camera.rotation = 0.0f;
    m_data.m_camera.zoom = 100.0f;
    return true;
}

bool Game::UpdateGame()
{
    ClearBackground(BLUE);
    m_deltaTime = GetFrameTime();
    if(m_deltaTime > 1.f / 5) { m_deltaTime = 1 / 5.f; }
    
    m_data.m_camera.offset = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};

    if (IsKeyDown(KEY_W)) m_data.m_camera.target.y -= 7 * m_deltaTime;
    if (IsKeyDown(KEY_S)) m_data.m_camera.target.y += 7 * m_deltaTime;
    if (IsKeyDown(KEY_A)) m_data.m_camera.target.x -= 7 * m_deltaTime;
    if (IsKeyDown(KEY_D)) m_data.m_camera.target.x += 7 * m_deltaTime;

    BeginMode2D(m_data.m_camera);

    for(int y = 0; y < m_data.gameMap.h; y++)
        for(int x = 0; x < m_data.gameMap.w; x++)
        {
            auto &b = m_data.gameMap.getBlockUnsafe(x, y);
            if(b.type != Block::air)
            {
                float size = 1;
                float posx = x * size;
                float posy = y * size;

                DrawTexturePro(
                    m_assetManager.dirt,
                    Rectangle{0.f,0.f,(float)m_assetManager.dirt.width,(float)m_assetManager.dirt.height},
                    {posx,posy,size,size},
                    {0,0},
                    0.0f,
                    WHITE
                );
            }

        }

    EndMode2D();
    return true;
}
void Game::CloseGame()
{
    
}

