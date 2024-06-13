#pragma once
#include "MovingObjects.h"


class Player:public MovingObjects
{
public:
	Player();
	int getLives()const;
	virtual void move(sf::Vector2f pos, float time);
	void createPlayer();
	bool isFying();

private:
	int m_lives;

	sf::Sprite m_flameSprite;
};