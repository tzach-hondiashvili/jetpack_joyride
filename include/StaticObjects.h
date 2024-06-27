#pragma once
#include "GameObjects.h"

class StaticObjects:public GameObjects
{
public:
	StaticObjects();
	virtual ~StaticObjects() {};
	virtual void updateAnimation(float ) override;

private:

};