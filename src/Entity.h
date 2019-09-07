//
// Created by Anton Z on 2019-09-01.
//

#ifndef INC_2DGAMEENGINE_ENTITY_H
#define INC_2DGAMEENGINE_ENTITY_H

#include <vector>
#include <string>
#include "./Component.h"
#include "./EntityManager.h"

class Component;
class EntityManager;

class Entity {
    private:
        bool isActive;
        std::vector<Component*> components;
        EntityManager &manager;

    public:
        std::string name;
        Entity(EntityManager &manager);
        Entity(EntityManager &manager, std::string name);
        void Update(float deltaTime);
        void Render();
        void Destroy();
        bool IsActive() const;

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args) {
            T* component(new T(std::forward<TArgs>(args)...));

            component->owner = this;
            components.push_back(component);
            component->Initialize();

            return *component;
        }
};


#endif //INC_2DGAMEENGINE_ENTITY_H
