#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <string>
#include "GameObjects.h"
#include "Coin.h"

//Typedef for a map storing factory functions for GameObject creation.
typedef std::map<std::string, std::unique_ptr<GameObjects>()> mymap;

//brief Factory class responsible for creating instances of GameObject based on name.
class Factory {
public:
    //Create a GameObject instance based on the provided name.
    static std::unique_ptr<GameObjects> create(const std::string& name);

    //Register a factory function for creating a GameObject by name.
    static bool registerit(const std::string& name, std::unique_ptr<GameObjects>(*)());

    // Methods to create different coin shapes
    static sf::VertexArray  createDiamond(const std::string& name);
    static sf::VertexArray  createRectangle(const std::string& name);
    static sf::VertexArray  createTriangle(const std::string& name);
    static sf::VertexArray  createCircle(const std::string& name);
    static sf::VertexArray  createHeart(const std::string& name);

private:
    //Get the static map of factory functions.
    static mymap& getMap()
    {
        static mymap m_map;
        return m_map;
    }
    static sf::VertexArray m_coinShapes;
};
