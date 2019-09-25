//
// Created by Anton Z on 26/09/2019.
//

#ifndef INC_2DGAME_ENGINE_MAP_H
#define INC_2DGAME_ENGINE_MAP_H

#include <string>

class Map {
    private:
        std::string textureId;
        int scale;
        int tileSize;

    public:
        Map(std::string textureId, int scale, int tileSize);
        ~Map();
        void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);
        void AddTile(int sourceX, int sourceY, int x, int y);
};


#endif //INC_2DGAME_ENGINE_MAP_H
