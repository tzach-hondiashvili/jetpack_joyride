#include "Map.h"

std::list<std::unique_ptr<Pickable>>& Map::getPickables()
{
	return m_pickables;
}

std::list<std::unique_ptr<StaticObjects>>& Map::getObstacles()
{
	return m_obstacles;
}

void Map::updatePickables(sf::Vector2f scrollOffset)
{
	auto temp = Factory::createAndGetPickables(scrollOffset);
	m_pickables.insert(m_pickables.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
}

void Map::updateObstacles(sf::Vector2f scrollOffset)
{
	auto temp = Factory::createAndGetObstacles(scrollOffset);
	m_obstacles.insert(m_obstacles.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
}

void Map::updatePickablesAnimation(float time)
{
	static float timeSinceLastFrame = 0.f;
	timeSinceLastFrame += time;

	if (timeSinceLastFrame >= 0.10f)
	{
		for (auto it = m_pickables.begin(); it != m_pickables.end(); it++)
		{
			(*it)->updateAnimation(time);
		}

		timeSinceLastFrame = 0;
	}
}

void Map::updateObstaclesAnimation(float time)
{
	static float timeSinceLastFrame = 0.f;
	timeSinceLastFrame += time;

	if (timeSinceLastFrame >= 0.10f)
	{
		for (auto it = m_obstacles.begin(); it != m_obstacles.end(); it++)
		{
			(*it)->updateAnimation(time);
		}

		timeSinceLastFrame = 0;
	}
}
