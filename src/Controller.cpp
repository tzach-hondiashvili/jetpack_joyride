#include "Controller.h"

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
