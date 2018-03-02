//
// Created by Valentín Holgado on 2/26/18.
//

#ifndef INC_2DGAME_GAMEOBJECT_H
#define INC_2DGAME_GAMEOBJECT_H


#include <SDL_system.h>

class GameObject {

public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos, yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};


#endif //INC_2DGAME_GAMEOBJECT_H
