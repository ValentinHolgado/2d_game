#ifndef INC_2DGAME_MAP_H
#define INC_2DGAME_MAP_H

#include "Game.h"

class GameMap {
public:
    GameMap();

    ~GameMap();

    void LoadMap(int arr[20][25]);

    void DrawMap();

private:

    SDL_Rect src, dest;

    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;

    int map[20][25];
};


#endif //INC_2DGAME_MAP_H
