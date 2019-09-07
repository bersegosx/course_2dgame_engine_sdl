//
// Created by Anton Z on 2019-09-01.
//

#ifndef INC_2DGAMEENGINE_COMPONENT_H
#define INC_2DGAMEENGINE_COMPONENT_H

class Entity;

class Component {
    private:
        Entity *owner;

    public:
        void Initialize();
        void Update(float deltaTime);
        void Render();
};


#endif //INC_2DGAMEENGINE_COMPONENT_H
