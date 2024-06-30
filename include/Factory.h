#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <string>
#include "GameObjects.h"
#include "Coin.h"
#include "Missile.h"
#include "Map.h"
#include <functional>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Enemy.h"

//Typedef for a map storing factory functions for GameObject creation.
typedef std::map<std::string, std::unique_ptr<GameObjects>(*)(sf::Vector2f position)> mymap;

//brief Factory class responsible for creating instances of GameObject based on name.
class Factory {
public:
    //Create a GameObject instance based on the provided name.
    static std::unique_ptr<GameObjects> create(const std::string& name, sf::Vector2f position);

    //Register a factory function for creating a GameObject by name.
    static bool registerit(const std::string& name, std::unique_ptr<GameObjects>(*)(sf::Vector2f position));

    //Logic function
    static std::list<std::unique_ptr<Pickable>> createAndGetPickables(sf::Vector2f scrollOffset, float gameTime);
    static std::list<std::unique_ptr<StaticObjects>> createAndGetObstacles(sf::Vector2f scrollOffset, float gameTime);
    static std::list<std::unique_ptr<Enemy>> createAndGetEnemies(sf::Vector2f scrollOffset,sf::Vector2f playerPos, float gameTime);
    static std::list<std::unique_ptr<MovingObjects>> createAndGetScientists(sf::Vector2f scrollOffset, sf::Vector2f playerPos, float gameTime);

    // Methods to create different coin shapes
    static std::list<std::unique_ptr<Pickable>> createDiamond(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Pickable>> createRectangle(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Pickable>> createTriangle(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Pickable>> createCircle(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Pickable>> createHeart(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Pickable>> createPowerup(const std::string& name, sf::Vector2f scrollOffset);

    // Methods to create different lazer shapes
    static std::list<std::unique_ptr<StaticObjects>> createYparallel(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<StaticObjects>> createXparallel(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<StaticObjects>> createLayingLeft(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<StaticObjects>> createLayingRight(const std::string& name, sf::Vector2f scrollOffset);

    // Methods to create different missile shapes
    static std::list<std::unique_ptr<Enemy>> createMissile(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Enemy>> create2oneByOne(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Enemy>> create4oneByOne(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Enemy>> create2together(const std::string& name, sf::Vector2f scrollOffset);
    static std::list<std::unique_ptr<Enemy>> create4together(const std::string& name, sf::Vector2f scrollOffset);

    // Methods to create scientists
    static std::list<std::unique_ptr<MovingObjects>> createScientists(const std::string& name, sf::Vector2f scrollOffset);

private:
    //Get the static map of factory functions.
    static mymap& getMap()
    {
        static mymap m_map;
        return m_map;
    }

};
