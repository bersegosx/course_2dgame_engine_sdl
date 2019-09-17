//
// Created by Anton Z on 2019-09-11.
//

#include "TextureManager.h"
#include "./Game.h"

SDL_Texture * TextureManager::LoadTexture(const char *fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect sourceRectangel, SDL_Rect destinationReactangle,
                          SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangel, &destinationReactangle, 0.0, NULL, flip);
}
