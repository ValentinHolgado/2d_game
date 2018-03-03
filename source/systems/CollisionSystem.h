//
// Created by Valentín Holgado on 3/3/18.
//

#ifndef INC_2DGAME_COLLISIONSYSTEM_H
#define INC_2DGAME_COLLISIONSYSTEM_H

#include <SDL_rect.h>
#include "System.h"
#include "../components/PositionComponent.h"
#include "../components/CollisionComponent.h"
#include "../components/DirectionComponent.h"

class CollisionSystem : public System {
public:
    CollisionSystem() = default;

    void Update(entt::DefaultRegistry &registry, double dt) override {
        for (auto left_entity : registry.view<PositionComponent, DirectionComponent, CollisionComponent>()) {
            for (auto right_entity : registry.view<PositionComponent, CollisionComponent>()) {
                if (left_entity == right_entity) continue;

                auto &left_position = registry.get<PositionComponent>(left_entity);
                auto &right_position = registry.get<PositionComponent>(right_entity);

                SDL_Rect left_rect{(int)left_position.x, (int)left_position.y, 32, 32};
                SDL_Rect right_rect{(int)right_position.x, (int)right_position.y, 32, 32};

                if (SDL_HasIntersection(&left_rect, &right_rect)) {
                    auto &direction = registry.get<DirectionComponent>(left_entity);

                    registry.destroy(right_entity);
                }
            }
        }
    }
};

#endif //INC_2DGAME_COLLISIONSYSTEM_H
