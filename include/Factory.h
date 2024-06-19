#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <string>
#include "GameObjects.h"
#include "Coin.h"
#include "Map.h"

//Typedef for a map storing factory functions for GameObject creation.
typedef std::map<std::string, std::unique_ptr<GameObjects>(*)(sf::Vector2f position)> mymap;

//brief Factory class responsible for creating instances of GameObject based on name.
class Factory {
public:
    //Create a GameObject instance based on the provided name.
    static std::unique_ptr<GameObjects> create(const std::string& name, sf::Vector2f position);

    //Register a factory function for creating a GameObject by name.
    static bool registerit(const std::string& name, std::unique_ptr<GameObjects>(*)(sf::Vector2f position));

    void createRandom();
    std::unique_ptr<GameObjects> createCoin(sf::Vector2f position);

    // Methods to create different coin shapes
    static std::unique_ptr<GameObjects> createDiamond(const std::string& name);
    static sf::VertexArray createRectangle(const std::string& name);
    static sf::VertexArray createTriangle(const std::string& name);
    static sf::VertexArray createCircle(const std::string& name);
    static sf::VertexArray createHeart(const std::string& name);

private:
    //Get the static map of factory functions.
    static mymap& getMap()
    {
        static mymap m_map;
        return m_map;
    }

};
