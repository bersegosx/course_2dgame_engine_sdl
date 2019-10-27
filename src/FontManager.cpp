//
// Created by Anton Z on 28/10/2019.
//

#include "FontManager.h"

TTF_Font * FontManager::LoadFont(const char *fileName, int fontSize) {
    return TTF_OpenFont(fileName, fontSize);
}

void FontManager::Draw(SDL_Texture *texture, SDL_Rect position) {
    SDL_RenderCopy(Game::renderer, texture, NULL, &position);
}