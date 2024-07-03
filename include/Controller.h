#pragma once
#include "map.h"
#include "Player.h"

class Controller
{
public:
	Controller();
	Player &getPlayer();
	void updatePlayerPos(sf::Vector2f pos, float time);
	Map &getMap();
	void checkCollision();
	void setIfCheckCollision(bool state);
	bool getIfCheckCollision();

private:
	Player m_player;
	Map m_map;
	bool m_ifCheckCollision;
};