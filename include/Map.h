#pragma once
#include <list>
#include "Pickable.h"
#include "Factory.h"
#include "Enemy.h"

class Map
{
public:
	Map() = default;

	std::list<std::unique_ptr <Pickable>>& getPickables();
	std::list<std::unique_ptr <StaticObjects>>& getObstacles();
	std::list<std::unique_ptr <Enemy>>& getEnemies();

	void updatePickables(sf::Vector2f scrollOffset);
	void updateObstacles(sf::Vector2f scrollOffset);
	void updateEnemies(sf::Vector2f scrollOffset, sf::Vector2f playerPos);

	void updatePickablesAnimation(float time);
	void updateObstaclesAnimation(float time);
	void updateEnemiesAnimation(float time);

	void resetMap();

	Map(Map&& other) noexcept;

private:
	//list because we are removing object from the board
	std::list<std::unique_ptr <Pickable>> m_pickables;      
	std::list<std::unique_ptr <StaticObjects>> m_obstacles; 
	std::list<std::unique_ptr <Enemy>> m_enemies; 
};