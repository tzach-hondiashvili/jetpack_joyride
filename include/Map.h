#pragma once
#include <list>
#include "Pickable.h"

class Map
{
public:
	void updatePickables(std::list<std::unique_ptr <Pickable>> object);
	void updateStaticObjects();

private:
	std::list<std::unique_ptr <Pickable>> m_pickables; //list because we are removing object from the board
	std::unique_ptr <std::list<StaticObjects>> m_obstacles;
};