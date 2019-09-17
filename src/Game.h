#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"

class AssetManager;

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
        void Initialize(int w, int h);
        void LoadLevel(int levelNumber);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};