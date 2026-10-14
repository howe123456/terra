#include "gameMain.h"


bool Game::InitGame()
{
    return true;
}

bool Game::UpdateGame()
{
    ClearBackground(BLACK);
    m_deltaTime = GetFrameTime();
    if(m_deltaTime > 1.f / 5) { m_deltaTime = 1 / 5.f; }
    if (IsKeyDown(KEY_A)) {m_pos.positionX -= 200 * m_deltaTime;}
    if (IsKeyDown(KEY_D)) {m_pos.positionX += 200 * m_deltaTime;}
    if (IsKeyDown(KEY_W)) {m_pos.positionY -= 200 * m_deltaTime;}
    if (IsKeyDown(KEY_S)) {m_pos.positionY += 200 * m_deltaTime;}
    DrawRectangle(m_pos.positionX,m_pos.positionY,20,20,RED);
    return true;
}
void Game::CloseGame()
{

}
