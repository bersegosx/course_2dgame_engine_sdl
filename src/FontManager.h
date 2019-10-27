//
// Created by Anton Z on 28/10/2019.
//

#ifndef INC_2DGAME_ENGINE_FONTMANAGER_H
#define INC_2DGAME_ENGINE_FONTMANAGER_H

#include "./Game.h"

class FontManager {
    public:
        static TTF_Font* LoadFont(const char* fileName, int fontSize);
        static void Draw(SDL_Texture* texture, SDL_Rect position);
};


#endif //INC_2DGAME_ENGINE_FONTMANAGER_H
