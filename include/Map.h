#pragma once
#include <list>
#include "Pickable.h"
#include "Factory.h"

class Map
{
public:
	std::list<std::unique_ptr <Pickable>>& getPickables();
	void updatePickables(sf::Vector2f scrollOffset);
	void updateStaticObjects();

private:
	std::list<std::unique_ptr <Pickable>> m_pickables; //list because we are removing object from the board
	std::unique_ptr <std::list<StaticObjects>> m_obstacles;
};