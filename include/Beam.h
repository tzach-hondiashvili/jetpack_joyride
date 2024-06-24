#pragma once
#include "Obstacles.h"
#include "Factory.h"

class Beam:public Obstacles
{
public:
	Beam(sf::Vector2f position);
	virtual ~Beam() override {};

	virtual void show();
	virtual void updateAnimation(float time) override;
private:
	static bool m_registerit;
};