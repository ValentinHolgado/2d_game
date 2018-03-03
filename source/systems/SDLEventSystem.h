//
// Created by Valentín Holgado on 2/27/18.
//

#ifndef INC_2DGAME_SDLEVENTSYSTEM_H
#define INC_2DGAME_SDLEVENTSYSTEM_H

#include <entt.hpp>
#include <SDL_events.h>
#include "System.h"
#include "../components/PositionComponent.h"
#include "../components/DirectionComponent.h"
#include "InputHandler.h"

class SDLEventSystem : public System {
public:

    explicit SDLEventSystem(bool &isRunning) : isRunning(isRunning) {}

    void Update(entt::DefaultRegistry &registry, double dt) override {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;

                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    InputHandler::Handle(registry, &event);
                    break;

                default:
                    break;
            }
        }
    }

private:
    bool &isRunning;
};

#endif //INC_2DGAME_SDLEVENTSYSTEM_H
