#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game {

    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        float timeSinceLastFrame;

        bool IsRunning() const;
        Game();
        ~Game();

        void Initialize(int w, int h);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};