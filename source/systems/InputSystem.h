//
// Created by Valentín Holgado on 3/2/18.
//

#ifndef INC_2DGAME_INPUTSYSTEM_H
#define INC_2DGAME_INPUTSYSTEM_H

#include <SDL_events.h>
#include <iostream>
#include "System.h"
#include "../components/DirectionComponent.h"
#include "../components/InputComponent.h"
#include "../utils/Log.h"

enum Movement {
    UP, LEFT, DOWN, RIGHT, NONE
};

class InputSystem {

public:
    InputSystem(entt::DefaultRegistry *registry) : registry_(registry) {}

    void Handle(const SDL_Event *pEvent) {
        Movement movement = NONE;
        Uint32 type = 0;
        type = pEvent->type;

        switch (pEvent->key.keysym.sym) {
            case SDLK_w:
                movement = UP;
                break;

            case SDLK_s:
                movement = DOWN;
                break;

            case SDLK_a:
                movement = LEFT;
                break;

            case SDLK_d:
                movement = RIGHT;
                break;

            default:
                break;
        }

        if (movement == NONE) return;

        UpdateEntities(registry_, movement, type);
    }

private:
    void UpdateEntities(entt::DefaultRegistry *es, const Movement &movement, Uint32 type) const {
        for (auto entity : es->view<InputComponent, DirectionComponent>()) {
            auto &direction = es->get<DirectionComponent>(entity);

            switch (type) {
                case SDL_KEYDOWN:
                    switch (movement) {
                        case UP:
                            direction.y = -2;
                            break;
                        case LEFT:
                            direction.x = -2;
                            break;
                        case DOWN:
                            direction.y = 2;
                            break;
                        case RIGHT:
                            direction.x = 2;
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    switch (movement) {
                        case UP:
                            direction.y = direction.y < 0 ? 0 : direction.y;
                            break;
                        case LEFT:
                            direction.x = direction.x < 0 ? 0 : direction.x;
                            break;
                        case DOWN:
                            direction.y = direction.y > 0 ? 0 : direction.y;
                            break;
                        case RIGHT:
                            direction.x = direction.x > 0 ? 0 : direction.x;
                            break;
                    }
                    break;
            }
        }
    }

private:
    entt::DefaultRegistry *registry_;
};

#endif //INC_2DGAME_INPUTSYSTEM_H
