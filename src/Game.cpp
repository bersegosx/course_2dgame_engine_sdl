#include <iostream>

#include "./Game.h"
#include "./Constants.h"
#include "../lib/glm/glm.hpp"

glm::vec2 ProjectilePos = glm::vec2(0.f, 0.f);
glm::vec2 ProjectileVel = glm::vec2(20.f, 30.f);

Game::Game() {}
Game::~Game() {}

bool Game::IsRunning() const {
    return isRunning;
}

void Game::Initialize(int w, int h) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error init SDL" << std::endl;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w,
        h,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        std::cerr << "Error init window" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error init renderer" << std::endl;
    }

    isRunning = true;
    return;
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT: {
            isRunning = false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }
         }
        default: {
            break;
        }
    }
}

void Game::Update() {
    // clamp fps
    SDL_Delay(MAX_TIME_PER_FRAME - ((SDL_GetTicks() - timeSinceLastFrame) / 1000.f));

    float deltaTime = (SDL_GetTicks() - timeSinceLastFrame) / 1000.f;

    ProjectilePos = glm::vec2(
        ProjectilePos.x + ProjectileVel.x * deltaTime,
        ProjectilePos.y + ProjectileVel.y * deltaTime
    );

    timeSinceLastFrame = SDL_GetTicks();
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    SDL_Rect projectile {
        (int) ProjectilePos.x,
        (int) ProjectilePos.y,
        10,
        10
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &projectile);

    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}