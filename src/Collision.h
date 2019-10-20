//
// Created by Anton Z on 20/10/2019.
//

#ifndef INC_2DGAME_ENGINE_COLLISION_H
#define INC_2DGAME_ENGINE_COLLISION_H

#include <SDL2/SDL.h>

class Collision {
    public:
        static bool CheckRectangleCollision(const SDL_Rect& rectangleA, const SDL_Rect& rectangleB);
};

#endif //INC_2DGAME_ENGINE_COLLISION_H
