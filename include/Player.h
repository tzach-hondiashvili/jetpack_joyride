#pragma once
#include "MovingObjects.h"


class Player:public MovingObjects
{
public:
	Player();
	int getLives()const;
	virtual void move();
	void createPlayer();

private:
	int m_lives;
	sf::Sprite m_playerSprite;
	sf::Sprite m_flameSprite;
};