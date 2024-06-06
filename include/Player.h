#pragma once
#include "MovingObjects.h"

class Player:public MovingObjects
{
public:
	Player();
	int getLives()const;
	virtual void move();
private:
	int m_lives;

};