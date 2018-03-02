//
// Created by Valentín Holgado on 2/26/18.
//

#ifndef INC_2DGAME_TEXTUREMANAGER_H
#define INC_2DGAME_TEXTUREMANAGER_H

#include <map>
#include "SDL2/SDL.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char *fileName);
    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
    static std::map<std::string, SDL_Texture*> textures;
};

#endif //INC_2DGAME_TEXTUREMANAGER_H
