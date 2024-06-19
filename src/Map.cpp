#include "Map.h"

void Map::updatePickables(std::list<std::unique_ptr <Pickable>> object)
{
	m_pickables.insert(m_pickables.end(), std::make_move_iterator(object.begin()), std::make_move_iterator(object.end()));
}


void Map::updateStaticObjects()
{
}
