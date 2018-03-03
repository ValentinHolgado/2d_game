#include <iostream>
#include "source/Game.h"
#include "source/utils/Log.h"

Game *game = nullptr;

int main() {
    game = new Game();
    game->init("2D_game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    while (game->Running()) {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update(frameTime);

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->Clean();

    return 0;
}