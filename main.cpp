#include <iostream>
#include "source/Game.h"

Game *game = nullptr;

int main() {
    game = new Game();
    game->init("2D_game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->Update(frameTime);
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}