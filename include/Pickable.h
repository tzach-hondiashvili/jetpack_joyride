#pragma once
#include "StaticObjects.h"

class Pickable:public StaticObjects
{
public:
	Pickable();
	virtual ~Pickable() {};

	virtual void updateAnimation(float time) override;
private:

};