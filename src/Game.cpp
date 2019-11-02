#include <iostream>

#include "./Constants.h"
#include "./Game.h"
#include "./AssetManager.h"
#include "./Map.h"
#include "./EntityManager.h"
#include "./Components/TransformComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Components/ColliderComponent.h"
#include "./Components/KeyboardControlComponent.h"
#include "./Components/TextLabelComponent.h"
#include "../lib/glm/glm.hpp"

glm::vec2 ProjectilePos = glm::vec2(0.f, 0.f);
glm::vec2 ProjectileVel = glm::vec2(20.f, 30.f);

EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
Map* map;

Game::Game() {}
Game::~Game() {}

bool Game::IsRunning() const {
    return isRunning;
}

void Game::Initialize(int w, int h) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error init SDL" << std::endl;
    }

    if (TTF_Init() != 0) {
        std::cerr << "Error init SDL TTF" << std::endl;
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

    LoadLevel(1);

    isRunning = true;
    return;
}

Entity& player(manager.AddEntity("chopper", PLAYER_LAYER));

void Game::LoadLevel(int levelNumber) {
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

    std::string levelName = "Level" + std::to_string(levelNumber);
    lua.script_file("./assets/scripts/" + levelName + ".lua");

    sol::table levelData = lua[levelName];
    sol::table levelAssets = levelData["assets"];

    // load assets from lua config
    std::cout << "game->LoadLevel" << std::endl;
    std::cout << " - load assets" << std::endl;
    unsigned int assetIndex = 0;
    while (true) {
        sol::optional<sol::table> existsAssetIndexNode = levelAssets[assetIndex];
        if (existsAssetIndexNode == sol::nullopt) {
            break;
        }

        sol::table asset = levelAssets[assetIndex];
        std::string assetType = asset["type"];
        if (assetType.compare("texture") == 0) {
            std::string assetId = asset["id"];
            std::string assetFile = asset["file"];
            assetManager->AddTexture(assetId, assetFile.c_str());
            std::cout << "   - add texture:" << assetId << ", " << assetFile << std::endl;
        }

        assetIndex++;
    }

    // load map from lua config
    std::cout << " - load map" << std::endl;
    sol::table levelMap = levelData["map"];
    std::string mapTextureId = levelMap["textureAssetId"];
    std::string mapFile = levelMap["file"];

    map = new Map(
        mapTextureId,
        static_cast<int>(levelMap["scale"]),
        static_cast<int>(levelMap["tileSize"])
    );
    std::cout << " - map created" << std::endl;

    map->LoadMap(
        mapFile,
        static_cast<int>(levelMap["mapSizeX"]),
        static_cast<int>(levelMap["mapSizeY"])
    );
    std::cout << " - map loaded" << std::endl;
}

void Game::ProcessInput() {
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
    timeSinceLastFrame = SDL_GetTicks();

    std::cout << " - manager.Update" << std::endl;
    manager.Update(deltaTime);

    std::cout << " - HandleCameraMovement" << std::endl;
//    HandleCameraMovement();

    std::cout << " - CheckCollisions" << std::endl;
    CheckCollisions();
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager.HasNoEntities()) {
        return;
    }
    manager.Render();

    SDL_RenderPresent(renderer);
}

void Game::HandleCameraMovement() {
    TransformComponent* mainPlayerTransform = player.GetComponent<TransformComponent>();
    camera.x = mainPlayerTransform->position.x  - (WINDOW_WIDTH / 2);
    camera.y = mainPlayerTransform->position.y  - (WINDOW_HEIGHT / 2);

    camera.x = camera.x < 0 ? 0 : camera.x;
    camera.y = camera.y < 0 ? 0 : camera.y;
    camera.x = camera.x > camera.w ? camera.w : camera.x;
    camera.y = camera.y > camera.h ? camera.h : camera.y;
}

void Game::CheckCollisions() {
    CollisionType collisionType = manager.CheckCollisions();
    std::cout << "CheckCollisions: " << collisionType << std::endl;
    if (collisionType == PLAYER_ENEMY_COLLISION) {
        ProcessGameOver();
    }
    if (collisionType == PLAYER_LEVEL_COMPLETE_COLLISION) {
        ProcessNextLevel(1);
    }
}

void Game::ProcessNextLevel(int levelNumber) {
    std::cout << "Next Level" << std::endl;
    isRunning = false;
}

void Game::ProcessGameOver() {
    std::cout << "Game Over" << std::endl;
    isRunning = false;
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}