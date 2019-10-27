#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;

const unsigned int FPS = 60;
const float MAX_TIME_PER_FRAME = 1000.0 / FPS;

enum CollisionType {
    NO_COLLISION,

    PLAYER_ENEMY_COLLISION,
    PLAYER_PROJECTILE_COLLISION,
    PLAYER_VEGETATION_COLLIDER,
    PLAYER_LEVEL_COMPLETE_COLLISION,

    ENEMY_PROJECTILE_COLLISION,
};

enum LayerType {
    TILEMAP_LAYER = 0,
    VEGETATION_LAYER = 1,
    ENEMY_LAYER = 2,
    PLAYER_LAYER = 3,
    PROJECTILE_LAYER = 4,
    UI_LAYER = 5,
    OBSTACLE_LAYER = 6,
};

const unsigned int NUM_LAYERS = 7;

const SDL_Color WHITE_COLOR = {255, 255, 255, 255};
const SDL_Color GREEN_COLOR = {0, 255, 0, 255};

#endif