#include <iostream>

#include "Constants.h"
#include "Game.h"

int main(int argc, char* args[]) {
    Game *game = new Game();
    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game->IsRunning()) {
        std::cout << "game->ProcessInput" << std::endl;
        game->ProcessInput();

        std::cout << "game->Update" << std::endl;
        game->Update();

        std::cout << "game->Render" << std::endl;
        game->Render();
    }

    game->Destroy();

    return 0;
}