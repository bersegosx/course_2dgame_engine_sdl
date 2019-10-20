//
// Created by Anton Z on 2019-09-01.
//

#ifndef INC_2DGAMEENGINE_ENTITY_H
#define INC_2DGAMEENGINE_ENTITY_H

#include <vector>
#include <string>
#include <map>
#include "./Constants.h"
#include "./Component.h"
#include "./EntityManager.h"

class Component;
class EntityManager;

class Entity {
    private:
        bool isActive;
        std::vector<Component*> components;
        EntityManager &manager;
        std::map<const std::type_info*, Component*> componentTypeMap;

    public:
        std::string name;
        LayerType layer;
        Entity(EntityManager &manager);
        Entity(EntityManager &manager, std::string name, LayerType layer);
        void Update(float deltaTime);
        void Render();
        void Destroy();
        bool IsActive() const;

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args) {
            T* component(new T(std::forward<TArgs>(args)...));

            component->owner = this;
            components.push_back(component);

            componentTypeMap[&typeid(*component)] = component;

            component->Initialize();

            return *component;
        }

        template <typename T>
        bool HasComponent() const {
            return componentTypeMap.count(&typeid(T));
        }

        template <typename T>
        T* GetComponent() {
            return static_cast<T*>(componentTypeMap[&typeid(T)]);
        }
};


#endif //INC_2DGAMEENGINE_ENTITY_H
