#pragma once
#include "Obstacles.h"
#include "Factory.h"

class Lazer:public Obstacles
{
public:
	Lazer(sf::Vector2f position);
	virtual void show();
	virtual void updateAnimation(float time) override;
private:
	static bool m_registerit;
};