#include "Controller.h"
#include "CollisionHandling.h"

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
		if (m_player.getSprite().getGlobalBounds().intersects((*it)->getSprite().getGlobalBounds()))
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
		sf::FloatRect playerBounds = m_player.getSprite().getTransform().transformRect(m_player.getSprite().getLocalBounds());
		sf::FloatRect obstacleBounds = (*it)->getSprite().getTransform().transformRect((*it)->getSprite().getLocalBounds());

		if (playerBounds.intersects(obstacleBounds)) 
		{
			processCollision(m_player, *(*it));
			break;
		}
	}

}
