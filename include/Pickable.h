#pragma once
#include "StaticObjects.h"

class Pickable:public StaticObjects
{
public:
	Pickable();
	virtual void updateAnimation(float time) override;
private:

};