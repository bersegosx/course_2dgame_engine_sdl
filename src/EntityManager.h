//
// Created by Anton Z on 2019-09-01.
//

#ifndef INC_2DGAMEENGINE_ENTITYMANAGER_H
#define INC_2DGAMEENGINE_ENTITYMANAGER_H

#include "./Entity.h"
#include "./Component.h"
#include <vector>

class EntityManager {
    private:
        std::vector<Entity*> entities;

    public:
        void ClearData();
        void Update(float deltaTime);
        void Render();
        bool HasNoEntities();
        Entity& AddEntity(std::string entityName, LayerType layer);
        CollisionType CheckCollisions() const;
        std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount();
};


#endif //INC_2DGAMEENGINE_ENTITYMANAGER_H
