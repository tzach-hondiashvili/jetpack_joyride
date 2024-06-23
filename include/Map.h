#pragma once
#include <list>
#include "Pickable.h"
#include "Factory.h"

class Map
{
public:
	std::list<std::unique_ptr <Pickable>>& getPickables();
	std::list<std::unique_ptr <StaticObjects>>& getObstacles();

	void updatePickables(sf::Vector2f scrollOffset);
	void updateObstacles(sf::Vector2f scrollOffset);

	void updatePickablesAnimation(float time);
	void updateObstaclesAnimation(float time);

private:
	std::list<std::unique_ptr <Pickable>> m_pickables;      //list because we are removing object from the board
	std::list<std::unique_ptr <StaticObjects>> m_obstacles; //list because we are removing object from the board
};