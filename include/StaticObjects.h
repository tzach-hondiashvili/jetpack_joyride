#pragma once
#include "GameObjects.h"

class StaticObjects:public GameObjects
{
public:
	StaticObjects();
	virtual void updateAnimation(float time) override;

private:

};