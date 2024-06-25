#pragma once
#include "MovingObjects.h"

class Enemy:public MovingObjects
{
public:
	virtual void move(sf::Vector2f pos, float time) = 0;
	virtual ~Enemy() {};
private:

};