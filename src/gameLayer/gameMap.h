#pragma once
#include <vector>
#include "Block.h"

struct g_gameMap {
    int w = 0;
    int h = 0;

    std::vector<Block> g_mapData;

    void create(int w, int h);
    
    Block &getBlockUnsafe(int x, int y);

    Block *getBlocksafe(int x, int y);
};