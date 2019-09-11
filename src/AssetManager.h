//
// Created by Anton Z on 2019-09-11.
//

#ifndef INC_2DGAMEENGINE_ASSETMANAGER_H
#define INC_2DGAMEENGINE_ASSETMANAGER_H

#include <map>
#include <string>
#include "./TextureManager.h"
#include "./EntityManager.h"

class AssetManager {
    private:
        EntityManager* manager;
        std::map<std::string, SDL_Texture*> textures;

    public:
        AssetManager(EntityManager* manager);
        ~AssetManager();
        void ClearData();
        void AddTexture(std::string textureId, const char* filePath);
        SDL_Texture* GetTexture(std::string textureId);
};


#endif //INC_2DGAMEENGINE_ASSETMANAGER_H
