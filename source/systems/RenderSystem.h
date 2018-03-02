//
// Created by Valentín Holgado on 3/2/18.
//

#ifndef INC_2DGAME_RENDERSYSTEM_H
#define INC_2DGAME_RENDERSYSTEM_H

#include "System.h"
#include "../components/PositionComponent.h"
#include "../components/TextureComponent.h"
#include "../Game.h"
#include "../TextureManager.h"

class RenderSystem : public System {
public:
    RenderSystem() = default;

    void update(entt::DefaultRegistry &registry, double dt) override {
        for (auto entity : registry.view<PositionComponent, TextureComponent>()) {
            auto &position = registry.get<PositionComponent>(entity);
            auto &textureComponent = registry.get<TextureComponent>(entity);

            SDL_Rect srcRect = CreateRect(0, 0, textureComponent.w, textureComponent.h);
            SDL_Rect destRect = CreateRect(position.x, position.y, textureComponent.w * 2, textureComponent.h * 2);

            SDL_Texture *texture = TextureManager::LoadTexture(textureComponent.texturePath);

            if (texture)
                SDL_RenderCopy(Game::renderer,
                           TextureManager::LoadTexture(textureComponent.texturePath),
                           &srcRect,
                           &destRect);
            else
                LOG("Texture not found");
        }
    }

    SDL_Rect CreateRect(int x, int y, int w, int h) const {
        SDL_Rect rect;

        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        return rect;
    }
};

#endif //INC_2DGAME_RENDERSYSTEM_H
