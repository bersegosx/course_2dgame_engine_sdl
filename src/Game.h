#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../lib/lua/sol.hpp"
#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"

class AssetManager;

#ifndef INC_2DGAME_ENGINE_GAME_H
#define INC_2DGAME_ENGINE_GAME_H

class Game {

    private:
        bool isRunning;
        SDL_Window *window;

    public:
        float timeSinceLastFrame;

        bool IsRunning() const;
        Game();
        ~Game();

        static SDL_Renderer *renderer;
        static AssetManager* assetManager;
        static SDL_Event event;
        static SDL_Rect camera;

        void Initialize(int w, int h);
        void LoadLevel(int levelNumber);
        void ProcessInput();
        void Update();
        void Render();
        void HandleCameraMovement();
        void Destroy();
        void CheckCollisions();

        void ProcessGameOver();
        void ProcessNextLevel(int);
};

#endif