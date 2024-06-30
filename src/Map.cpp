#include "Map.h"

std::list<std::unique_ptr<Pickable>>& Map::getPickables()
{
	return m_pickables;
}

std::list<std::unique_ptr<StaticObjects>>& Map::getObstacles()
{
	return m_obstacles;
}

std::list<std::unique_ptr<Enemy>>& Map::getEnemies()
{
	return m_enemies;
}

std::list<std::unique_ptr<MovingObjects>>& Map::getScientists()
{
	return m_scientists;
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

void Map::updateEnemies(sf::Vector2f scrollOffset, sf::Vector2f playerPos)
{
	auto temp = Factory::createAndGetEnemies(scrollOffset, playerPos);
	m_enemies.insert(m_enemies.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
}

void Map::updateScientists(sf::Vector2f scrollOffset, sf::Vector2f playerPos)
{
	auto temp = Factory::createAndGetScientists(scrollOffset, playerPos);
	m_scientists.insert(m_scientists.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
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

	if (timeSinceLastFrame >= 0.08f)
	{
		for (auto it = m_obstacles.begin(); it != m_obstacles.end(); it++)
		{
			(*it)->updateAnimation(time);
		}

		timeSinceLastFrame = 0;
	}
}

void Map::updateEnemiesAnimation(sf::Vector2f pos, float time)
{
	static float timeSinceLastFrame = 0.f;
	timeSinceLastFrame += time;

	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
	{
		(*it)->move({ (*it)->getSprite().getPosition().x, (*it)->getSprite().getPosition().y }, time);		
	}

	if (timeSinceLastFrame >= 0.08f)
	{

		for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
		{

			(*it)->updateAnimation(time);
			(*it)->updateSoundAndWarnings(pos);

		}
		timeSinceLastFrame = 0;
	}
	
}

void Map::updateScientistsAnimation(sf::Vector2f , float time)
{
	static float timeSinceLastFrame = 0.f;
	timeSinceLastFrame += time;

	for (auto it = m_scientists.begin(); it != m_scientists.end(); it++)
	{
		(*it)->move({ (*it)->getSprite().getPosition().x, (*it)->getSprite().getPosition().y }, time);
	}

	if (timeSinceLastFrame >= 0.08f)
	{

		for (auto it = m_scientists.begin(); it != m_scientists.end(); it++)
		{
			(*it)->updateAnimation(time);
		}
		timeSinceLastFrame = 0;
	}
}

void Map::updateMap(sf::Vector2f viewPos, float time)
{
	updatePickablesAnimation(time);
	updateObstaclesAnimation(time);
	updateEnemiesAnimation(viewPos, time);
	updateScientistsAnimation(viewPos,time);

	// deleting passed objects
	for (auto it = m_pickables.begin(); it != m_pickables.end(); )
	{
		if ((*it)->CheckIfToDelete(viewPos))
		{
			it = m_pickables.erase(it); 
		}
		else
		{
			++it; 
		}
	}

	for (auto it = m_obstacles.begin(); it != m_obstacles.end(); )
	{
		if ((*it)->CheckIfToDelete(viewPos))
		{
			it = m_obstacles.erase(it);

		}
		else
		{
			++it;
		}
	}

	for (auto it = m_enemies.begin(); it != m_enemies.end(); )
	{
		if ((*it)->CheckIfToDelete(viewPos))
		{
			it = m_enemies.erase(it); 
		}
		else
		{
			++it; 
		}
	}

	for (auto it = m_scientists.begin(); it != m_scientists.end(); )
	{
		if ((*it)->CheckIfToDelete(viewPos))
		{
			it = m_scientists.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Map::resetMap()
{
	m_enemies.clear();
	m_obstacles.clear();
	m_pickables.clear();
}

Map::Map(Map&& other) noexcept
	: m_pickables(std::move(other.m_pickables)),
	m_obstacles(std::move(other.m_obstacles)),
	m_enemies(std::move(other.m_enemies))
{

}
