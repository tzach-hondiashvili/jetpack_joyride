#pragma once
#include "MovingObjects.h"

class Enemy:public MovingObjects
{
public:
	Enemy();
	virtual void move(sf::Vector2f pos, float time) = 0;
	virtual void updateSoundAndWarnings(sf::Vector2f pos) = 0;
	virtual sf::Sprite getWarning() = 0;
	bool getIsPlayed();
	bool setIsPlayed(bool state);
	virtual ~Enemy() {};
private:
	bool m_isPlayed;
};