//
// Created by Valentín Holgado on 2/27/18.
//

#ifndef INC_2DGAME_MOVEMENTSYSTEM_H
#define INC_2DGAME_MOVEMENTSYSTEM_H

#include <entt.hpp>
#include "System.h"
#include "../components/PositionComponent.h"
#include "../components/DirectionComponent.h"

class MovementSystem : public System {
public:
    MovementSystem() = default;

    void Update(entt::DefaultRegistry &registry, double dt) override {
        for (auto entity : registry.view<PositionComponent, DirectionComponent>()) {
            auto &position = registry.get<PositionComponent>(entity);
            auto &direction = registry.get<DirectionComponent>(entity);
            position.x += direction.x * dt;
            position.y += direction.y * dt;
        }
    }
};

#endif //INC_2DGAME_MOVEMENTSYSTEM_H
