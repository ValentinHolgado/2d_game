//
// Created by Valentín Holgado on 2/26/18.
//

#include "Game.h"
#include "utils/Log.h"
#include "GameObject.h"
#include "GameMap.h"
#include "components/PositionComponent.h"
#include "systems/MovementSystem.h"
#include "systems/RenderSystem.h"
#include <entt.hpp>

GameObject *player;

GameMap *map;

SDL_Renderer *Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    Uint32 flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        LOG("Subsystems Initialised!...");

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if (window) {
            LOG("Window created!");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            LOG("Renderer created!");
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    this->systems_.emplace_back(std::make_unique<MovementSystem>());
    this->systems_.emplace_back(std::make_unique<RenderSystem>());

    registry_.create<PositionComponent, DirectionComponent, TextureComponent>();

    player = new GameObject("../assets/character_right.png", 0, 0);
    map = new GameMap();
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::Update(double deltaTime) {
    player->Update();

    SDL_RenderClear(renderer);
    map->DrawMap();

    for (auto& system : systems_) {
        system->update(registry_, deltaTime);
    }

    SDL_RenderPresent(renderer);
}

void Game::render() {
    //player->Render();
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    LOG("Game cleaned");
}

bool Game::running() {
    return isRunning;
}