//
// Created by Anton Z on 28/10/2019.
//

#ifndef INC_2DGAME_ENGINE_TEXTLABELCOMPONENT_H
#define INC_2DGAME_ENGINE_TEXTLABELCOMPONENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../FontManager.h"
#include "../EntityManager.h"
#include "../AssetManager.h"
#include "../Game.h"

class TextLabelComponent: public Component {
    private:
        SDL_Rect position;
        std::string text;
        std::string fontFamily;
        SDL_Color color;
        SDL_Texture* texture;

    public:
        TextLabelComponent(int x, int y, std::string text, std::string fontFamily, const SDL_Color color) {
            this->position.x = x;
            this->position.y = y;
            this->text = text;
            this->fontFamily = fontFamily;
            this->color = color;

            SetLabelText(text, fontFamily);
        }

        void SetLabelText(std::string text, std::string fontFamily) {
            SDL_Surface* surface = TTF_RenderText_Blended(Game::assetManager->GetFont(fontFamily), text.c_str(), color);
            texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
            SDL_FreeSurface(surface);
            SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
        }

        void Render() override {
            FontManager::Draw(texture, position);
        }
};

#endif //INC_2DGAME_ENGINE_TEXTLABELCOMPONENT_H
