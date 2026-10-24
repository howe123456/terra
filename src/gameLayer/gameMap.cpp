#include "gameMap.h"
#include "asserts.h"

void g_gameMap::create(int w, int h) { 
    *this = {};
    g_mapData.resize(w * h);

    this->w = w;
    this->h = h;

    for(auto &e : g_mapData) {
        e = {};
    }

}

Block &g_gameMap::getBlockUnsafe(int x, int y)
{
    permaAssertCommentDevelopenment(g_mapData.size() == w * h, "Map data not initialized");
    permaAssertCommentDevelopenment(x >= 0 && y >=0 && x < w && y < h, "GetBlockUnsafe out of bounds error");
    return g_mapData[x + y * w];
}

Block *g_gameMap::getBlocksafe(int x, int y)
{
    permaAssertCommentDevelopenment(g_mapData.size() == w * h, "Map data not initialized");
    if(x >= 0 && y >=0 && x < w && y < h) {
        return &g_mapData[x + y * w];
    }
    return nullptr;
}