#pragma once
#include "GameObjects.h"

class MovingObjects:public GameObjects
{
public:
	MovingObjects();
	virtual ~MovingObjects() {};
	virtual void updateAnimation(float ) override;
	virtual void move(sf::Vector2f pos, float time) = 0;

private:

};