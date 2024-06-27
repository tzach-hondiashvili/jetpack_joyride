#pragma once
#include "MovingObjects.h"

class Enemy:public MovingObjects
{
public:
	Enemy();
	virtual void move(sf::Vector2f pos, float time) = 0;
	virtual void updateSoundAndWarnings(sf::Vector2f pos) = 0;
	virtual sf::Sprite getWarning() = 0;
	virtual sf::Sprite getBeforeMissile() = 0;
	bool getIsLaunchPlayed();
	bool setIsLaunchPlayed(bool state);
	bool getIsWarningPlayed();
	bool setIsWarningPlayed(bool state);
	virtual ~Enemy() {};
private:
	bool m_isLaunchPlayed;
	bool m_isWarningPlayed;
};