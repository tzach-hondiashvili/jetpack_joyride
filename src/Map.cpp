#include "Map.h"

std::list<std::unique_ptr<Pickable>>& Map::getPickables()
{
	return m_pickables;
}

void Map::updatePickables(sf::Vector2f scrollOffset)
{
	auto temp = Factory::createAndGetPickables(scrollOffset);
	m_pickables.insert(m_pickables.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
}


void Map::updateStaticObjects()
{
}
