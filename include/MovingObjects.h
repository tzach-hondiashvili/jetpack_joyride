#pragma once
#include "GameObjects.h"

class MovingObjects:public GameObjects
{
public:
	virtual void move(sf::Vector2f pos, float time) = 0;
	virtual ~MovingObjects() {};

private:

};