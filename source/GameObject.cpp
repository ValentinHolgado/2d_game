//
// Created by Valentín Holgado on 2/26/18.
//

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(const char *textureSheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(textureSheet);

    xPos = x;
    yPos = y;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}

GameObject::~GameObject() {

}

void GameObject::Update() {
    xPos++;

    destRect.x = xPos;
    destRect.y = yPos;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
