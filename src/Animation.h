//
// Created by Anton Z on 25/09/2019.
//

#ifndef INC_2DGAME_ENGINE_ANIMATION_H
#define INC_2DGAME_ENGINE_ANIMATION_H

class Animation {
    public:
        unsigned int index;
        unsigned int numFrames;
        unsigned int animationSpeed;

        Animation();
        Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed);
};

#endif //INC_2DGAME_ENGINE_ANIMATION_H
