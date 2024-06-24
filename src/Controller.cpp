#include "Controller.h"
#include "CollisionHandling.h"

Controller::Controller()
	:m_map({})
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


	//check collision with obstacles
	/*for (auto it = m_map.getObstacles().begin(); it != m_map.getObstacles().end(); it++)
	{
		if (m_player.getSprite().getGlobalBounds().intersects((*it)->getSprite().getGlobalBounds()))
		{
			processCollision(m_player, *(*it));
			break;
		}
	}*/
}
