#pragma once
#include "GameObjects.h"

class MovingObjects:public GameObjects
{
public:
	virtual void move() = 0;

private:

};