//
// Created by Valentín Holgado on 2/26/18.
//

#include "Game.h"
#include "GameObject.h"
#include "components/PositionComponent.h"
#include "systems/MovementSystem.h"
#include "systems/RenderSystem.h"

SDL_Renderer *Game::renderer = nullptr;

Game::Game() {
}

Game::~Game() {

}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {

    initGraphics(title, xPos, yPos, width, height, fullscreen);

    initSystems();

    auto player = registry_.create<InputComponent, PositionComponent, DirectionComponent>();

    registry_.assign<SpriteComponent>(player, "../assets/character_right.png");
}

void Game::initSystems() {
    systems_.emplace_back(std::make_unique<MovementSystem>());
    systems_.emplace_back(std::make_unique<RenderSystem>());
}

void Game::initGraphics(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
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
}

// TODO: Handle all events in a separate system.
void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                inputSystem.Handle(&event);
                break;

            default:
                break;
        }
    }
}

void Game::Update(double deltaTime) {
    for (auto &system : systems_) {
        system->Update(registry_, deltaTime);
    }
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    LOG("Game cleaned");
}

bool Game::Running() {
    return isRunning;
}
