#include "Controller.h"
#include "CollisionHandling.h"
#include "Collision.h"

Controller::Controller()
{

}

Player& Controller::getPlayer()
{
	return m_player;
}

void Controller::updatePlayerPos(sf::Vector2f pos, float time)
{
	m_player.move(pos,time);
}

Map& Controller::getMap()
{
	return m_map;
}

void Controller::checkCollision()
{
	auto pickable2Remove = m_map.getPickables().end();


	//check collision with pickables
	for (auto it = m_map.getPickables().begin(); it != m_map.getPickables().end(); it++)
	{
		if (m_player.getState()->getCurrSkin().getGlobalBounds().intersects((*it)->getSprite().getGlobalBounds()))
		{
			processCollision(m_player, *(*it));
			pickable2Remove = it;
			break;
		}
	}
	if (pickable2Remove != m_map.getPickables().end())
	{
		m_map.getPickables().remove(*pickable2Remove);
		return;
	}


	for (auto it = m_map.getObstacles().begin(); it != m_map.getObstacles().end(); it++)
	{
		if (Collision::pixelPerfectTest(m_player.getState()->getCurrSkin(), (*it)->getSprite(), 128))
		{
			processCollision(m_player, *(*it));
			break; // Exit loop on first collision found
		}
	}

	for (auto it = m_map.getEnemies().begin(); it != m_map.getEnemies().end(); it++)
	{
		if (Collision::pixelPerfectTest(m_player.getState()->getCurrSkin(), (*it)->getSprite(), 128))
		{
			processCollision(m_player, *(*it));
			break; // Exit loop on first collision found
		}
	}
}
