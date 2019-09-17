//
// Created by Anton Z on 2019-09-11.
//

#ifndef INC_2DGAMEENGINE_TEXTUREMANAGER_H
#define INC_2DGAMEENGINE_TEXTUREMANAGER_H

#include <SDL2/SDL.h>

class TextureManager {
    public:
        static SDL_Texture* LoadTexture(const char* fileName);
        static void Draw(SDL_Texture* texture, SDL_Rect sourceRectangel, SDL_Rect destinationReactangle, SDL_RendererFlip flip);
};

#endif //INC_2DGAMEENGINE_TEXTUREMANAGER_H
