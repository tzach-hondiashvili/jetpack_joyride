#pragma once
#include "MovingObjects.h"

class Enemy:public MovingObjects
{
public:
	virtual void move() = 0;
private:

};