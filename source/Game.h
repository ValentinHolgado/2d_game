//
// Created by Valentín Holgado on 2/26/18.
//

#ifndef INC_2DGAME_GAME_H
#define INC_2DGAME_GAME_H


#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "systems/System.h"
#include <iostream>
#include <vector>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();
    void Update(double deltaTime);
    void render();
    void clean();

    bool running();

    static SDL_Renderer* renderer;

private:
    bool isRunning = false;
    SDL_Window* window;
    entt::DefaultRegistry registry_;
    std::vector<std::unique_ptr<System>> systems_;
};


#endif //INC_2DGAME_GAME_H
