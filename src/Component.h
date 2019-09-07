//
// Created by Anton Z on 2019-09-01.
//

#ifndef INC_2DGAMEENGINE_COMPONENT_H
#define INC_2DGAMEENGINE_COMPONENT_H

class Entity;

class Component {
    public:
        Entity *owner;

        virtual void Initialize();
        virtual void Update(float deltaTime);
        virtual void Render();
};


#endif //INC_2DGAMEENGINE_COMPONENT_H
