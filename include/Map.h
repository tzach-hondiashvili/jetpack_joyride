#pragma once
#include <list>
#include "Pickable.h"

class Map
{
public:

private:
	std::list<Pickable> m_pickables; //list because we are removing object from te board
	std::list<StaticObjects> m_obstacles;
};