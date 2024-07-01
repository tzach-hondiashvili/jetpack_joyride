#pragma once
#include "StaticObjects.h"
#include <iostream>
#include "Factory.h"
#include "Resources.h"
#include <cstdlib>
#include <ctime>   

class Alarm :public StaticObjects
{
public:
	Alarm(sf::Vector2f position);
	virtual ~Alarm() override {};

	virtual void show();
	virtual void updateAnimation(float) override;

private:
	static bool m_registerit;
};
