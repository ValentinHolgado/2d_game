#include "TextureManager.h"
#include "Game.h"
#include <SDL_image.h>

std::map<std::string, SDL_Texture*> TextureManager::textures;

SDL_Texture *TextureManager::LoadTexture(const char *fileName) {
    if (fileName == NULL || fileName == nullptr) {
        return nullptr;
    }

    SDL_Texture* texture = textures[fileName];

    if (!texture) {
        SDL_Surface *tempSurface = IMG_Load(fileName);
        texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        textures.insert(std::make_pair(fileName, texture));
    }

    return texture;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
