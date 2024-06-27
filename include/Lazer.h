#pragma once
#include "Obstacles.h"
#include "Factory.h"

class Lazer:public Obstacles
{
public:
	Lazer(sf::Vector2f position);
	virtual ~Lazer() override{};

	virtual void show();
	virtual void updateAnimation(float ) override;
private:
	static bool m_registerit;
};